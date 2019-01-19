#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
struct binomial_heap {
    int val, rank, id;
    binomial_heap *child, *R, *parent;
 
    binomial_heap() {
        this->parent = NULL;
        this->val = 0;
        this->rank = 0;
        this->id = -1;
        this->child = NULL;
        this->R = NULL;
    }
};
 
const int MAXN = ll(1ll << 31ll) - 1;
vector< pair<int, int> > id_val;
vector< vector<int> > heap_id;
vector<binomial_heap*> heaps, pointers;
binomial_heap* head = NULL;
 
binomial_heap *newest_heap = NULL, *_start = NULL;
 
void sort(binomial_heap* v) {
    if (v == NULL) {
        return;
    }
 
    sort(v->R);
 
    if (newest_heap == NULL) {
        newest_heap = new binomial_heap();
        _start = newest_heap;
    }
 
    v->parent = NULL;
    v->R = NULL;
    newest_heap->R = v;
    newest_heap = newest_heap->R;
}
 
binomial_heap* unite(binomial_heap* v1, binomial_heap* v2) {
    if (v1->val > v2->val || (v1->val == v2->val && v1->id > v2->id)) {
        v2->R = NULL;
        v1->R = NULL;
        v1->R = v2->child;
        v1->parent = v2;
        v2->child = v1;
        v2->rank++;
 
        return v2;
    } else {
        v2->R = NULL;
        v1->R = NULL;
        v2->R = v1->child;
        v2->parent = v1;
        v1->child = v2;
        v1->rank++;
 
        return v1;
    }
}
 
binomial_heap* merge(binomial_heap* v1, binomial_heap* v2) {
    vector<int> r(1e6 + 2);
    binomial_heap* new_heap = new binomial_heap();
    binomial_heap* cur = new_heap;
 
    while (v1 != NULL && v2 != NULL) {
        if (v1->rank < v2->rank) {
            cur->R = v1;
            pointers[v1->id] = cur->R;
            cur = cur->R;
            r[v1->rank]++;
            v1 = v1->R;
        } else {
            cur->R = v2;
            pointers[v2->id] = cur->R;
            cur = cur->R;
            r[v2->rank]++;
            v2 = v2->R;
        }
    }
    while (v1 != NULL) {
        cur->R = v1;
        pointers[v1->id] = cur->R;
        cur = cur->R;
        r[v1->rank]++;
        v1 = v1->R;
    }
    while (v2 != NULL) {
        cur->R = v2;
        pointers[v2->id] = cur->R;
        cur = cur->R;
        r[v2->rank]++;
        v2 = v2->R;
    }
 
    cur = new_heap->R;
    binomial_heap *prev = new_heap;
 
    while (cur != NULL) {
        if (cur->R != NULL && cur->rank == cur->R->rank) {
            if (r[cur->rank] == 3) {
                prev = prev->R;
                cur = cur->R;
            }
            binomial_heap *right = cur->R->R;
            cur = unite(cur, cur->R);
            if (cur == NULL) {
                break;
            }
            r[cur->rank]++;
            cur->R = right;
            pointers[cur->id] = cur;
            if (prev != NULL) {
                prev->R = cur;
            }
            continue;
        }
        prev = prev->R;
        cur = cur->R;
    }
 
    return new_heap->R;
}
 
binomial_heap* extract_min(binomial_heap* v) {
    if (v == NULL) {
        return NULL;
    }
 
    int min_val = MAXN, min_id = MAXN;
    binomial_heap *min_elem = v, *cur = v;
 
    while (cur != NULL) {
        if (cur->val < min_val || (cur->val == min_val && cur->id < min_id)) {
            min_val = cur->val;
            min_id = cur->id;
            min_elem = cur;
        }
        cur = cur->R;
    }
    cur = v;
    while (cur != NULL && cur->R != NULL) {
        if (cur->R == min_elem) {
            cur->R = cur->R->R;
        }
        cur = cur->R;
    }
    if (v == min_elem) {
        v = v->R;
    }
 
    newest_heap = NULL;
    _start = NULL;
    sort(min_elem->child);
    if (_start == NULL) {
        return v;
    }
 
    return merge(v, _start->R);
}
 
binomial_heap* insert(binomial_heap* v, int x, int id) {
    binomial_heap* new_node = new binomial_heap();
 
    new_node->val = x;
    new_node->id = id;
 
    return merge(v, new_node);
}
 
void decrease_key(binomial_heap* v, int new_x) {
    if (v == NULL) {
        return;
    }
 
    v->val = new_x;
    pointers[v->id] = v;
 
    while (v != NULL) {
        if (v->parent != NULL) {
            if (v->val < v->parent->val || (v->val == v->parent->val && v->id < v->parent->id)) {
                swap(v->val, v->parent->val);
                swap(v->id, v->parent->id);
                pointers[v->id] = v;
                pointers[v->parent->id] = v->parent;
            }
        }
        v = v->parent;
    }
}
 
void del(binomial_heap* v) {
    decrease_key(v, -MAXN);
    head = extract_min(head);
}
 
void increase_key(binomial_heap* v, int new_x) {
    int _id = v->id;
    int _val = new_x;
    del(v);
    head = insert(head, _val, _id);
}
 
int get_min(binomial_heap* v) {
    int min_val = MAXN;
 
    while (v != NULL) {
        if (v->val < min_val) {
            min_val = v->val;
        }
        v = v->R;
    }
 
    return min_val;
}
 
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, c, a, b;
 
    cin >> n >> m;
    heap_id.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        heaps.push_back(NULL);
    }
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == 0) {
            cin >> a >> b;
 
            pointers.push_back(NULL);
            heaps[a - 1] = insert(heaps[a - 1], b, sz(id_val));
            heap_id[a - 1].push_back(sz(id_val));
            id_val.push_back(make_pair(a - 1, b));
        }
        if (c == 1) {
            cin >> a >> b;
 
            for (int j = 0; j < sz(heap_id[a - 1]); j++) {
                heap_id[b - 1].push_back(heap_id[a - 1][j]);
                id_val[heap_id[a - 1][j]].first = b - 1;
            }
 
            heap_id[a - 1].clear();
            heaps[b - 1] = merge(heaps[a - 1], heaps[b - 1]);
            heaps[a - 1] = NULL;
        }
        if (c == 2) {
            cin >> a;
 
            head = heaps[id_val[a - 1].first];
            binomial_heap* found = pointers[a - 1];
            del(found);
            heaps[id_val[a - 1].first] = head;
        }
        if (c == 3) {
            cin >> a >> b;
 
            int ival = id_val[a - 1].second;
            head = heaps[id_val[a - 1].first];
            binomial_heap* found = pointers[a - 1];
            if (ival > b) {
                decrease_key(found, b);
                heaps[id_val[a - 1].first] = head;
            } else {
                increase_key(found, b);
                heaps[id_val[a - 1].first] = head;
            }
            id_val[a - 1].second = b;
        }
        if (c == 4) {
            cin >> a;
 
            cout << get_min(heaps[a - 1]) << endl;
        }
        if (c == 5) {
            cin >> a;
 
            heaps[a - 1] = extract_min(heaps[a - 1]);
        }
    }
 
    return 0;
}
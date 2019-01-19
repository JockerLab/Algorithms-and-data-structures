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
 
struct str{
    int _min, _max, cnt, root;
};
 
vector<int> r;
vector<str> p;
 
void upd(str &a, int &b) {
    a.root = b;
    p[b].cnt = a.cnt + p[b].cnt;
    p[b]._min = min(a._min, p[b]._min);
    p[b]._max = max(a._max, p[b]._max);
}
 
int get(int a) {
    if (p[a].root != a) {
        p[a].root = get(p[a].root);
    }
    return p[a].root;
}
 
void join(int a, int b) {
    a = get(a);
    b = get(b);
 
    if (a == b) {
        return;
    }
 
    if (r[a] == r[b]) {
        r[a]++;
    }
 
    if (r[a] > r[b]) {
        upd(p[b], a);
    } else {
        upd(p[a], b);
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, u, v;
    string q;
 
    cin >> n;
 
    p.resize(n);
    r.resize(n);
 
    for (int i = 0; i < n; i++) {
        p[i].root = i;
        p[i]._min = i;
        p[i]._max = i;
        p[i].cnt = 1;
    }
 
    while (cin >> q) {
        if (q == "union") {
            cin >> u >> v;
 
            u--;
            v--;
 
            join(u, v);
        } else {
            cin >> u;
 
            u--;
 
            int ans = get(u);
 
            cout << p[ans]._min + 1 << " " << p[ans]._max + 1 << " " << p[ans].cnt << endl;
        }
    }
 
    return 0;
}
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
 
const int INF = 1e9 + 2, MAXQ = int(ll(1 << 31) - 1);
 
vector<int> p;
 
int get(int a) {
    if (p[a] != a) {
        p[a] = get(p[a]);
    }
 
    return p[a];
}
 
void join(int a, int b) {
    a = get(a);
    b = get(b);
 
    if (a == b) {
        return;
    }
 
    p[a] = b;
}
 
struct str {
    int l, r, c;
};
 
vector<str> values;
 
int partition(vector<str> &a, int l, int r) {
    int x = a[(l + r) / 2].c, i = l, j = r;
 
    while (i <= j) {
        while (a[i].c < x) {
            i++;
        }
        while (a[j].c > x) {
            j--;
        }
        if (i >= j) {
            break;
        }
 
        swap(a[i++], a[j--]);
    }
 
    return j;
}
 
void quick_sort(vector<str> &a, int l, int r) {
    if (l < r) {
        int pos = partition(a, l, r);
        quick_sort(a, l, pos);
        quick_sort(a, pos + 1, r);
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, a, b, c;
 
    cin >> n >> m;
 
    vector<int> ans(n, -INF);
    p.resize(n + 1);
 
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
 
        values.push_back({ a, b, c });
    }
 
    quick_sort(values, 0, sz(values) - 1);
 
    for (int i = sz(values) - 1; i >= 0; i--) {
        int l = values[i].l, r = values[i].r, color = values[i].c;
        l--;
        r--;
 
        int res = l;
 
        while (res <= r) {
            int res = get(l);
 
            if (res > r) {
                break;
            }
 
            ans[res] = color;
 
            join(l, res + 1);
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (ans[i] == -INF) {
            cout << MAXQ << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
 
    return 0;
}
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
 
struct str {
    int root, lazy, color;
};
 
int cur_res = 0;
vector<int> r;
vector<str> p;
 
int get(int a) {
    if (p[a].root == a) {
        cur_res += p[a].lazy;
        return a;
    }
 
    int res = get(p[a].root);
 
    cur_res += p[a].lazy;
 
    return res;
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
        p[b].root = a;
        p[b].lazy -= p[a].lazy;
    } else {
        p[a].root = b;
        p[a].lazy -= p[b].lazy;
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, a, b, c, zerg = 0, p1 = 1e6 + 3;
 
    cin >> n >> m;
 
    p.resize(n);
    r.resize(n);
 
    for (int i = 0; i < n; i++) {
        p[i].root = i;
        p[i].color = 0;
        p[i].lazy = 0;
        r[i] = 0;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> c;
 
        if (c == 1) {
            cin >> a;
            p[get((a + zerg) % n)].lazy++;
            zerg = (30 * zerg + 239) % p1;
        }
        if (c == 2) {
            cin >> a >> b;
 
            if (get((a + zerg) % n) != get((b + zerg) % n)) {
                join((a + zerg) % n, (b + zerg) % n);
                zerg = (13 * zerg + 11) % p1;
            }
        }
        if (c == 3) {
            cin >> a;
            a = (a + zerg) % n;
            cur_res = 0;
            get(a);
            cur_res -= p[a].color;
            p[a].color += cur_res;
            cout << cur_res << endl;
            zerg = int(ll(100500ll * zerg + cur_res) % p1);
        }
    }
 
    return 0;
}
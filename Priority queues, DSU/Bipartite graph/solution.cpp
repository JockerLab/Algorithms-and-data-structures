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
 
int cur_res;
vector<int> r;
vector<str> p;
 
int get(int a) {
    if (p[a].root == a) {
        cur_res ^= p[a].lazy;
        return a;
    }
 
    int res = get(p[a].root);
 
    cur_res ^= p[a].lazy;
 
    return res;
}
 
void join(int a, int b) {
    cur_res = 0;
    a = get(a);
    int color_a = cur_res ^ p[a].color;
    cur_res = 0;
    b = get(b);
    int color_b = cur_res ^ p[b].color;
 
    if (a == b) {
        return;
    }
 
    if (r[a] == r[b]) {
        r[a]++;
    }
 
    if (r[a] > r[b]) {
        p[b].root = a;
        if (color_a == color_b) {
            p[b].lazy ^= 1;
        }
    } else {
        p[a].root = b;
        if (color_a == color_b) {
            p[a].lazy ^= 1;
        }
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, a, b, c, shift = 0;
 
    cin >> n >> m;
 
    p.resize(n);
    r.resize(n);
 
    for (int i = 0; i < n; i++) {
        p[i].root = i;
        p[i].color = 0;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
 
        a = (a + shift) % n;
        b = (b + shift) % n;
 
        if (c == 0) {
            join(a, b);
        } else {
            cur_res = 0;
            int x = get(a);
            x = p[x].color ^ cur_res;
            cur_res = 0;
            int y = get(b);
            y = p[y].color ^ cur_res;
 
            if (x != y) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                shift++;
                shift %= n;
            }
        }
    }
 
    return 0;
}
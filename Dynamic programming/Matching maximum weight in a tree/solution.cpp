#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
vector<ll> d1, d2;
vector< vector< pair<int, ll> > > g;
 
void dfs(int v, int p = -1) {
    for (int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i].first;
 
        if (to != p) {
            dfs(to, v);
        }
    }
 
    if (sz(g[v]) != 0) {
        ll sum = 0;
 
        for (int i = 0; i < sz(g[v]); i++) {
            int to = g[v][i].first;
            if (to != p) {
                sum += max(d1[to], d2[to]);
            }
        }
        for (int i = 0; i < sz(g[v]); i++) {
            int to = g[v][i].first;
            ll c = g[v][i].second;
            if (to != p) {
                d1[v] = max(d1[v], c + sum - max(d1[to], d2[to]) + d2[to]);
            }
        }
 
        d2[v] = sum;
    }
}
 
int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, a, b;
    ll w;
    cin >> n;
 
    g.resize(n);
    d1.resize(n);
    d2.resize(n);
 
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> w;
 
        a--;
        b--;
 
        g[a].push_back({ b, w });
        g[b].push_back({ a, w });
    }
 
    dfs(0);
 
    cout << max(d1[0], d2[0]);
 
    return 0;
}
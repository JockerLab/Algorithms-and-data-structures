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
 
const ll INF = ll(1e18);
 
using namespace std;
 
int main() {
    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, a, b;
    ll w;
 
    cin >> n >> m;
 
    if (n == 1 && m == 0) {
        cout << 0;
        return 0;
    }
 
    vector< vector<ll> > d(n, vector<ll>(1 << n, INF));
    vector< vector<pair<int, ll>> > g(n);
 
    for (int i = 0; i < n; i++) {
        d[i][(1 << i)] = 0;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
 
        a--;
        b--;
        g[a].push_back({ b, w });
        g[b].push_back({ a, w });
    }
 
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0) {
                continue;
            }
 
            for (int j = 0; j < sz(g[i]); j++) {
                int to = g[i][j].first;
                ll c = g[i][j].second;
                if (((1 << to) & mask) == 0) {
                    d[to][((1 << to) | mask)] = min(d[to][((1 << to) | mask)], d[i][mask] + c);
                }
            }
        }
    }
 
    ll ans = INF;
 
    for (int i = 0; i < n; i++) {
        ans = min(ans, d[i][(1 << n) - 1]);
    }
 
    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans;
    }
 
    return 0;
}
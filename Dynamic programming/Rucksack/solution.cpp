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
 
const int INF = 1e9;
 
using namespace std;
 
int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
    ll m;
 
    cin >> n >> m;
 
    vector< vector<ll> > d(m + 1, vector<ll>(n + 1));
    vector<ll> w(n), c(n);
 
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= m; i++) {
            if (d[i][j] || !i) {
                d[i][j + 1] = max(d[i][j], d[i][j + 1]);
                if (i + w[j] <= m) {
                    d[i + w[j]][j + 1] = max(d[i + w[j]][j + 1], d[i][j] + c[j]);
                }
            }
        }
    }
    ll _max = 0;
    int id = 0;
 
    for (int i = 0; i <= m; i++) {
        if (_max < d[i][n]) {
            _max = d[i][n];
            id = i;
        }
    }
    vector<int> ans;
    m = id;
    int k = n;
    for (int i = n - 1; k > 0 && i >= 0; i--) {
        if (d[m][k] == d[m][k - 1]) {
            k--;
            continue;
        }
        if (m - w[i] >= 0 && d[m][k] == d[m - w[i]][k - 1] + c[i]) {
            k--;
            ans.push_back(i);
            m -= w[i];
        }
    }
 
    cout << sz(ans) << endl;
 
    for (int i = sz(ans) - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
    }
 
    return 0;
}
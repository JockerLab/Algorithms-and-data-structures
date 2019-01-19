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
 
const ll INF = 1e18;
 
using namespace std;
 
vector< vector<ll> > d;
vector< vector<int> > p;
 
string rec(int l, int r) {
    if (l == r) {
        return "A";
    }
 
    string s1 = "", s2 = "";
 
    if (p[l][r] != -1) {
        s1 = rec(l, p[l][r] - 1);
        s2 = rec(p[l][r], r);
        if (sz(s1) > 1) {
            s1 = "(" + s1 + ")";
        }
        if (sz(s2) > 1) {
            s2 = "(" + s2 + ")";
        }
    }
 
    return s1 + s2;
}
 
int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    vector< pair<ll, ll> > a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
 
    d.resize(n);
    p.resize(n);
 
    for (int i = 0; i < n; i++) {
        d[i].resize(n);
        p[i].resize(n);
        for (int j = 0; j < n; j++) {
            p[i][j] = -1;
            d[i][j] = 0;
        }
    }
 
    for (int len = 1; len < n; len++) {
        for (int l = 0; l < n - len; l++) {
            int r = l + len;
            for (int k = l + 1; k <= r; k++) {
                if (d[l][r] > d[l][k - 1] + d[k][r] + a[l].first * a[k].first * a[r].second || !d[l][r]) {
                    d[l][r] = d[l][k - 1] + d[k][r] + a[l].first * a[k].first * a[r].second;
                    p[l][r] = k;
                }
            }
        }
    }
 
    string ans = rec(0, n - 1);
 
    if (sz(ans) > 1) {
        ans = "(" + ans + ")";
    }
 
    cout << ans;
 
    return 0;
}
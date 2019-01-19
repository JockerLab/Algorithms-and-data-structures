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
 
const ll MOD = ll(999999937);
 
using namespace std;
 
vector< vector<ll> > mul(vector< vector<ll> > a, vector< vector<ll> > b) {
    vector< vector<ll> > res(5, vector<ll>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}
 
int main() {
    freopen("sequences.in", "r", stdin);
    freopen("sequences.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n;
 
    vector< vector<ll> > d(5, vector<ll>(5, 1));
    vector< vector<ll> > e(5, vector<ll>(5));
    d[2][3] = 0ll;
    d[2][4] = 0ll;
    d[4][3] = 0ll;
    d[4][4] = 0ll;
 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                e[i][j] = 1ll;
            }
        }
    }
 
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
 
        vector< vector<ll> > d1 = d;
        vector< vector<ll> > res = e;
        ll p = n - 1ll;
        while (p > 0ll) {
            if (p % 2ll != 0ll) {
                res = mul(res, d1);
                p--;
            }
            d1 = mul(d1, d1);
            p /= 2ll;
        }
 
        ll ans = 0ll;
 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ans = (ans + res[i][j]) % MOD;
            }
        }
 
        cout << ans << endl;
    }
 
    return 0;
}
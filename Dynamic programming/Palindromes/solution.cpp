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
 
const ll MOD = ll(1e9);
 
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    vector<int> a(n);
    vector< vector<ll> > d(n + 1, vector<ll>(n + 1));
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
 
        d[0][i] = 1ll;
    }
 
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            d[len][i] = (d[len - 1][i] + d[len - 1][i + 1]) % MOD;
            d[len][i] %= MOD;
            if (len - 2 >= 0) {
                if (a[i] != a[i + len]) {
                    d[len][i] = (d[len][i] - d[len - 2][i + 1] + MOD) % MOD;
                }
            }
            if (a[i] == a[i + len]) {
                d[len][i]++;
                d[len][i] %= MOD;
            }
        }
    }
 
    cout << d[n - 1][0];
 
    return 0;
}
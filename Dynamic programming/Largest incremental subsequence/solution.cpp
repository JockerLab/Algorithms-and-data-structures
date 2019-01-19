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
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, max_id = 0;
 
    cin >> n;
 
    vector<int> a(n), dp(n + 1, INF + 1), p(n + 1), _max(n + 1), ans;
 
    dp[0] = -INF - 1;
    p[0] = -1;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
 
        int l = 0, r = n;
 
        while (l + 1 < r) {
            int mid = (l + r) / 2;
 
            if (dp[mid] < a[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }
 
        dp[r] = a[i];
        p[i] = _max[r - 1];
        if (!i) {
            p[i] = -1;
        }
        _max[r] = i;
        max_id = max(max_id, r);
    }
 
    for (int i = _max[max_id]; p[i] != -1; i = p[i]) {
        ans.push_back(a[i]);
    }
 
    if (a[_max[0]] <= ans[sz(ans) - 1]) {
        ans.push_back(a[_max[0]]);
    }
 
    cout << sz(ans) << endl;
 
    for (int i = sz(ans) - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
 
    return 0;
}
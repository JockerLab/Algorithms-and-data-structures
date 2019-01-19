#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <queue>
 
#define sz(s) int(s.size())
typedef long long ll;
 
using namespace std;
 
const ll MAXN = 10000000000ll;
const ll MAXCNT = 100000000ll;
 
ll partition(vector<ll> &a, ll l, ll r) {
    ll x = a[(l + r) / 2ll], i = l, j = r;
 
    while (i <= j) {
        while (a[i] < x) {
            i++;
        }
        while (a[j] > x) {
            j--;
        }
        if (i >= j) {
            break;
        }
 
        swap(a[i++], a[j--]);
    }
 
    return j;
}
 
void quick_sort(vector<ll> &a, ll l, ll r) {
    if (l < r) {
        ll pos = partition(a, l, r);
        quick_sort(a, l, pos);
        quick_sort(a, pos + 1ll, r);
    }
}
 
int main() {
    freopen("supermarket.in", "r", stdin);
    freopen("supermarket.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int m, n, b, t;
    ll p;
 
    cin >> m;
 
    vector< pair<int, int> > a(m);
 
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> b >> t;
 
        a[i].second = b + t;
    }
 
    cin >> n >> p;
 
    ll l = -1ll , r = MAXN;
 
    while (l + 1ll < r) {
        ll mid = (r + l) / 2ll;
 
        vector<ll> new_a;
 
        for (int i = 0; i < m; i++) {
            if (mid - a[i].second < 0ll) {
                new_a.push_back(0ll);
                continue;
            }
 
            if (a[i].first == 0) {
                new_a.push_back(MAXCNT);
            } else {
                new_a.push_back((mid - ll(a[i].second)) / ll(a[i].first));
            }
        }
 
        quick_sort(new_a, 0ll, ll(sz(new_a)) - 1ll);
 
        ll sum = 0ll;
 
        for (int i = sz(new_a) - 1; i >= max(0, sz(new_a) - n); i--) {
            sum += ll(new_a[i]);
        }
 
        if (sum >= p) {
            r = mid;
        } else {
            l = mid;
        }
    }
 
    cout << r;
 
    return 0;
}
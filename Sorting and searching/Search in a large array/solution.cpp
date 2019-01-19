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
 
const ll MAXN = 1000000000000000000ll;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    ll x, m, b1, l = 0ll, r = 0ll, b, l1, r1;
 
    cin >> x >> m;
 
    vector<ll> a(2 * m + 100);
 
    cout << "? 1" << endl;
 
    cin >> b1;
 
    if (b1 == x) {
        cout << "! " << 1 << endl;
        return 0;
    }
 
    if (b1 < x) {
        l = max(1ll, x - b1 - m + 1ll);
        r = max(1ll, x - b1 + 1ll);
    } else {
        l = min(MAXN - m, MAXN - m - (b1 - x - 1ll));
        r = min(MAXN - m, MAXN - m - (b1 - x - 1ll - m));
    }
 
    l1 = l;
    r1 = r;
 
    a[0] = b1;
 
    if (m == 0) {
        if (b1 < x) {
            cout << "! " << x - b1 + 1ll << endl;
        } else {
            cout << "! " << MAXN - (b1 - x - 1ll) << endl;
        }
 
        return 0;
    }
 
    if (l + 1ll >= r) {
        cout << "? " << l << endl;
 
        cin >> b1;
 
        if (b1 == x) {
            cout << "! " << l << endl;
            return 0;
        }
 
        cout << "? " << r << endl;
 
        cin >> b1;
 
        if (b1 == x) {
            cout << "! " << r << endl;
            return 0;
        }
 
        cout << "! -1" << endl;
 
        return 0;
    }
 
    while (l + 1ll < r) {
        ll mid = (l + r) / 2ll;
 
        if (a[mid - l1 + 1] != 0) {
            ll i = mid - l1 + 1ll;
 
            while (i < ll(sz(a)) || a[i] != 0) {
                i++;
            }
 
            if (i - 1ll + l1 > r1) {
                i = mid - l1 + 1;
 
                while (a[i] != 0) {
                    i--;
                }
            }
 
            cout << "? " << i << endl;
            cin >> b;
            a[i] = b;
        } else {
            cout << "? " << mid << endl;
            cin >> b;
            a[mid - l1 + 1] = b;
        }
 
        if (b == x) {
            cout << "! " << mid << endl;
            return 0;
        }
 
        if ((x < b && b1 < b && b1 < x) || (b < b1 && x < b1 && x < b) || (b < b1 && b1 < x)) {
            r = mid;
 
            if (l + 1 >= r) {
                if (a[l - l1 + 1] != 0) {
                    b = a[l - l1 + 1];
                } else {
                    cout << "? " << l << endl;
                    cin >> b;
                }
                if (b == x) {
                    cout << "! " << l << endl;
                    return 0;
                } else {
                    cout << "! -1" << endl;
                    return 0;
                }
            }
        } else {
            l = mid;
 
            if (l + 1 >= r) {
                cout << "! -1" << endl;
                return 0;
            }
        }
    }
 
    cout << "! -1" << endl;
 
    return 0;
}
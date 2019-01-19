#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <queue>
 
#define sz(s) int(s.size())
typedef long long ll;
 
using namespace std;
 
int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, b;
 
    cin >> n;
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> b;
 
        int l = -1, r = n - 1;
 
        while (l + 1 < r) {
            int m = (l + r) / 2;
 
            if (a[m] < b) {
                l = m;
            } else {
                r = m;
            }
        }
 
        if (a[r] != b) {
            cout << -1 << " " << -1 << endl;
            continue;
        }
 
        cout << r + 1 << " ";
 
        l = 0, r = n;
 
        while (l + 1 < r) {
            int m = (l + r) / 2;
 
            if (a[m] <= b) {
                l = m;
            } else {
                r = m;
            }
        }
 
        cout << l + 1 << endl;
    }
 
    return 0;
}
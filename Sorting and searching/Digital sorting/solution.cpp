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
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, k;
 
    cin >> n >> m >> k;
 
    vector<string> a(n), new_a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> c(27), h(27);
    vector<int> r(n);
 
    for (int it = 0; it < k; it++) {
        for (int i = 0; i < n; i++) {
            r[i] = 0;
        }
        for (int i = 0; i < 27; i++) {
            c[i] = 0;
            h[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            c[a[i][m - it - 1] - 'a']++;
        }
 
        int pointer = 0;
 
        for (int i = 0; i < 27; i++) {
            h[i] = pointer;
            pointer += c[i];
        }
        for (int i = 0; i < n; i++) {
            r[h[a[i][m - it - 1] - 'a']++] = i;
        }
        for (int i = 0; i < n; i++) {
            new_a[i] = a[r[i]];
        }
 
        a = new_a;
    }
 
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
 
    return 0;
}
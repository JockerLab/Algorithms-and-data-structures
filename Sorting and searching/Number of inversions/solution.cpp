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
 
unsigned int cur = 0, a, b, m;
 
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}
 
ll ans = 0;
 
vector<unsigned int> merge_sort(vector<unsigned int> &a) {
    if (sz(a) == 1) {
        return a;
    }
 
    vector<unsigned int> res(sz(a)), l, r;
 
    for (int i = 0; i < sz(a) / 2; i++) {
        l.push_back(a[i]);
    }
 
    for (int i = sz(a) / 2; i < sz(a); i++) {
        r.push_back(a[i]);
    }
 
    l = merge_sort(l);
    r = merge_sort(r);
 
    int i = 0, j = 0, cnt = 0;
 
    while (i < sz(l) || j < sz(r)) {
        if (i < sz(l) && j < sz(r)) {
            if (l[i] <= r[j]) {
                res[cnt++] = l[i++];
            } else {
                res[cnt++] = r[j++];
                ans += sz(l) - i;
            }
        } else {
            if (i < sz(l)) {
                res[cnt++] = l[i++];
            } else {
                res[cnt++] = r[j++];
            }
        }
    }
 
    return res;
}
 
int main() {
    freopen("invcnt.in", "r", stdin);
    freopen("invcnt.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n >> m >> a >> b;
    vector<unsigned int> arr(n);
 
    for (int i = 0; i < n; i++) {
        arr[i] = nextRand24() % m;
    }
 
    arr = merge_sort(arr);
 
    cout << ans;
 
    return 0;
}
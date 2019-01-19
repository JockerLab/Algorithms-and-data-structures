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
 
vector<int> merge_sort(vector<int> &a) {
    if (sz(a) == 1) {
        return a;
    }
 
    vector<int> res(sz(a)), l, r;
 
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
            if (l[i] < r[j]) {
                res[cnt++] = l[i++];
            } else {
                res[cnt++] = r[j++];
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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
 
    cin >> n;
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    a = merge_sort(a);
 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
 
    return 0;
}
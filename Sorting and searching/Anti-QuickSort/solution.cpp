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
 
int main() {
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    vector<pair<int, int>> a(n);
    vector<int> ans(n);
 
    for (int i = 0; i < n; i++) {
        a[i].second = i;
    }
 
    int i = n - 1, num = n;
 
    while (i >= 0) {
        a[i / 2].first = num;
        ans[a[i / 2].second] = num;
        num--;
        swap(a[i / 2], a[i]);
        i--;
    }
 
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
 
    return 0;
}
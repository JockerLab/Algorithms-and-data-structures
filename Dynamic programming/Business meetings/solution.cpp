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
 
using namespace std;
 
int cnt(int a) {
    int res = 0;
 
    while (a)
        res += (a & 1), a >>= 1;
    return res;
}
 
int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, k;
 
    cin >> n >> k;
 
    vector<int> a(n), b(n), c(n);
    vector<bool> d(1 << n);
    vector<int> p(1 << n, -1);
    d[0] = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (((1 << j) & i) == 0 && d[i]) {
                int sum = k;
                for (int t = 0; t < n; t++)
                    if ((1 << t) & i) {
                        sum += c[t];
                    }
                if (a[j] <= sum && sum <= b[j]) {
                    d[(i | (1 << j))] = true;
                    p[(i | (1 << j))] = j;
                }
            }
        }
    }
    int max_cnt = 0, max_mask = 0, last = -1;
    for (int i = (1 << n) - 1; i >= 0; i--) {
        if (d[i]) {
            if (cnt(i) > max_cnt) {
                max_cnt = cnt(i);
                max_mask = i;
                last = p[i];
            }
        }
    }
    cout << max_cnt << endl;
 
    vector<int> visited;
 
    for (int i = last; i != -1; i = p[max_mask]) {
        visited.push_back(i + 1);
        max_mask ^= (1 << i);
    }
 
    for (int i = sz(visited) - 1; i >= 0; i--) {
        cout << visited[i] << " ";
    }
 
    return 0;
}
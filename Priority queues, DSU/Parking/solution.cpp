#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
vector<int> p;
 
int get(int a) {
    if (p[a] != a) {
        p[a] = get(p[a]);
    }
    return p[a];
}
 
void join(int a, int b) {
    a = get(a);
    b = get(b);
 
    if (a == b) {
        return;
    }
 
    p[a] = b;
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, a;
 
    cin >> n;
 
    p.resize(n);
 
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
 
        int ans = get(a - 1);
 
        cout << ans + 1 << " ";
 
        join(ans, (ans + 1) % n);
    }
 
    return 0;
}
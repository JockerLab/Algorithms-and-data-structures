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
 
vector<int> r, p;
 
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
 
    if (r[a] == r[b]) {
        r[a]++;
    }
 
    if (r[a] > r[b]) {
        p[b] = a;
    } else {
        p[a] = b;
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, k, u, v;
    string s;
 
    cin >> n >> m >> k;
 
    p.resize(n);
    r.resize(n);
 
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
    }
 
    vector< pair< string, pair< int, int > > > q(k);
 
    for (int i = 0; i < k; i++) {
        cin >> s >> u >> v;
 
        q[i].first = s;
        q[i].second.first = u - 1;
        q[i].second.second = v - 1;
    }
 
    vector<string> ans;
 
    for (int i = k - 1; i >= 0; i--) {
        if (q[i].first == "ask") {
            if (get(q[i].second.first) == get(q[i].second.second)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        } else {
            join(q[i].second.first, q[i].second.second);
        }
    }
 
    for (int i = sz(ans) - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
 
    return 0;
}
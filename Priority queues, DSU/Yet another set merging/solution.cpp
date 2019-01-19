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
 
int get(vector<int> &p, int a) {
    if (p[a] != a) {
        p[a] = get(p, p[a]);
    }
 
    return p[a];
}
 
void join(vector<int> &p, int a, int b) {
    a = get(p, a);
    b = get(p, b);
 
    if (a == b) {
        return;
    }
 
    if (p[a] < b) {
        p[a] = b;
    } else {
        p[b] = a;
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, a, b, c;
 
    cin >> n >> m;
 
    vector<int> p1(n + 1), p2(n + 1);
 
    for (int i = 0; i <= n; i++) {
        p1[i] = i;
        p2[i] = i;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;
 
        a--;
        b--;
 
        if (b < a) {
            swap(a, b);
        }
 
        if (c == 1) {
            join(p1, a, b);
        }
        if (c == 2) {
            while (a < b) {
                a = get(p2, a);
 
                if (a >= b) {
                    break;
                }
 
                join(p2, a, a + 1);
                join(p1, a, a + 1);
            }
        }
        if (c == 3) {
            if (get(p1, a) == get(p1, b)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
 
    return 0;
}
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
 
const double eps = 1e-9;
 
bool check(double a1, double a, int n) {
    int i = 3;
    double a2 = a / 1000000.0;
 
    while (1) {
        double a3 = 2.0 * a2 - a1 + 2.0;
 
        if (i > n) {
            return true;
        }
        if (a3 <= eps) {
            return false;
        }
        if (a3 - a2 > eps) {
            return true;
        }
 
        a1 = a2;
        a2 = a3;
        i++;
    }
}
 
void print(double a1, double a, int n) {
    double a3 = 0.0, a2 = a / 1000000.0;
    for (int i = 2; i < n; i++) {
        a3 = 2.0 * a2 - a1 + 2.0;
        a1 = a2;
        a2 = a3;
    }
 
    printf("%.2lf", a3);
}
 
int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
    double a, a1;
 
    cin >> n >> a;
 
    a1 = a * 1000000.0;
 
    double l = 0, r = a1 + 1.0;
 
    for(int it = 0; it < 1000; it++) {
        double m = (l + r) / 2.0;
 
        if (!check(a, m, n)) {
            l = m;
        } else {
            r = m;
        }
    }
 
    print(a, r, n);
 
    return 0;
}
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
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s1, s2, s;
    int cnt = 0, flag = 0;
 
    cin >> s1 >> s2;
 
    s1 = "A" + s1;
    s2 = "A" + s2;
 
    for (int i = 0; i < sz(s1); i++) {
        if (s1[i] == '*') {
            if (!flag) {
                s += s1[i];
            }
            flag = 1;
            cnt++;
        } else {
            flag = 0;
            s += s1[i];
        }
    }
 
    vector< vector<ll> > d(sz(s2), vector<ll>(3));
 
    cnt = sz(s1) - cnt;
    s1 = s;
    int c = 1;
    for (int j = 1; j < sz(s1); j++) {
        if (s1[j] != '*') {
            c++;
        }
        for (int i = 1; i < sz(s2); i++) {
            if (s1[j] == s2[i]) {
                d[i][1] = d[i - 1][0] + 1;
            } else {
                if (s1[j] == '?') {
                    d[i][1] = d[i - 1][0] + 1;
                } else {
                    if (s1[j] == '*') {
                        if (i >= c) {
                            d[i][1] = max(max(d[i - 1][0], d[i - 1][1]) + 1, d[i][0]);
                        } else {
                            d[i][1] = d[i][0];
                        }
                    } else {
                        d[i][1] = 0;
                    }
                }
            }
        }
 
        for (int i = 1; i < sz(s2); i++) {
            d[i][0] = d[i][1];
            d[i][1] = 0;
        }
    }
 
    if (d[sz(s2) - 1][0] != sz(s2) - 1 || cnt > sz(s2)) {
        cout << "NO";
    } else {
        cout << "YES";
    }
 
    return 0;
}
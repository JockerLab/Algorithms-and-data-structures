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
    freopen("levenshtein.in", "r", stdin);
    freopen("levenshtein.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    string s, s1, s2;
 
    cin >> s1 >> s2;
 
    vector< vector<int> > d(sz(s1), vector<int>(sz(s2)));
 
    int flag = 1;
    for (int i = 0; i < sz(s1); i++) {
        if (s1[i] == s2[0]) {
            flag = 0;
        }
        d[i][0] = i + flag;
    }
    flag = 1;
    for (int j = 0; j < sz(s2); j++) {
        if (s1[0] == s2[j]) {
            flag = 0;
        }
        d[0][j] = j + flag;
    }
 
    for (int i = 1; i < sz(s1); i++) {
        for (int j = 1; j < sz(s2); j++) {
            if (s1[i] == s2[j]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1]));
                d[i][j]++;
            }
        }
    }
 
    cout << d[sz(s1) - 1][sz(s2) - 1];
 
    return 0;
}
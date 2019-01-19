#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; i++) {
        if ((i * 2 + 1 < n) && (a[i] > a[i * 2 + 1])) {
            cout << "NO";
            return 0;
        }
        if ((i * 2 + 2 < n) && (a[i] > a[i * 2 + 2])) {
            cout << "NO";
            return 0;
        }
    }
 
    cout << "YES";
 
    return 0;
}
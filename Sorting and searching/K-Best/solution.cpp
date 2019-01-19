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
 
int partition(vector< pair< pair<double, double>, int > > &a, int l, int r) {
    int i = l, j = r;
    int pos = (l + r) / 2;
    double x = a[pos].first.second - a[pos].first.first;
 
    while (i <= j) {
        while ((a[i].first.second - a[i].first.first) < x) {
            i++;
        }
        while ((a[j].first.second - a[j].first.first) > x) {
            j--;
        }
        if (i >= j) {
            break;
        }
 
        swap(a[i++], a[j--]);
    }
 
    return j;
}
 
void quick_sort(vector< pair< pair<double, double>, int > > &a, int l, int r) {
    if (l < r) {
        int pos = partition(a, l, r);
        quick_sort(a, l, pos);
        quick_sort(a, pos + 1, r);
    }
}
 
int k, n;
 
bool f(double m, vector< pair< pair<double, double>, int > > a) {
    double s = 0;
 
    for (int i = 0; i < n; i++) {
        a[i].first.second *= m;
    }
 
    quick_sort(a, 0, n - 1);
 
    for (int i = 0; i < k; i++) {
        s += (a[i].first.second - a[i].first.first);
    }
 
    if (s <= 0) {
        return true;
    } else {
        return false;
    }
}
 
int main() {
    freopen("kbest.in", "r", stdin);
    freopen("kbest.out", "w", stdout);
 
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    vector< pair< pair<double, double>, int > > a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
 
    quick_sort(a, 0, n - 1);
 
    double l = 0, r = double(1e7 / n);
 
    for (int it = 0; it < 50; it++) {
        double m = (l + r) / 2.0;
 
        if (f(m, a)) {
            l = m;
        } else {
            r = m;
        }
    }
 
    for (int i = 0; i < n; i++) {
        a[i].first.second *= l;
    }
 
    quick_sort(a, 0, n - 1);
 
    for (int i = 0; i < k; i++) {
        cout << a[i].second + 1 << " ";
    }
 
    return 0;
}
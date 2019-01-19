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
 
int partition(vector<int> &a, int l, int r) {
    int x = a[(l + r) / 2];
 
    while (l <= r) {
        while (a[l] < x) {
            l++;
        }
        while (a[r] > x) {
            r--;
        }
        if (l >= r) {
            break;
        }
 
        swap(a[l++], a[r--]);
    }
 
    return r;
}
 
void quick_sort(vector<int> &a, int l, int r, int k) {
    if (l < r) {
        int pos = partition(a, l, r);
 
        if (pos >= k - 1) {
            quick_sort(a, l, pos, k);
        } else {
            quick_sort(a, pos + 1, r, k);
        }
    } else {
        cout << a[l];
        exit(0);
    }
}
 
int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, k, a, b, c, a1, a2;
 
    cin >> n >> k >> a >> b >> c >> a1 >> a2;
 
    vector<int> arr(n);
 
    arr[0] = a1;
    arr[1] = a2;
 
    for (int i = 2; i < n; i++) {
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    }
 
    quick_sort(arr, 0, n - 1, k);
 
    return 0;
}
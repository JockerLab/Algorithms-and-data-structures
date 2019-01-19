#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <queue>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
unsigned int cur = 0, a1, b1;
const int MAXN = (1 << 16), N = 100001;
 
inline unsigned int nextRand24() {
    cur = cur * a1 + b1;
    return (cur >> 8);
}
 
inline unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return ((a << 8) ^ b);
}
 
unsigned int arr[N];
unsigned int arr1[N];
unsigned int r[N];
int c[MAXN], h[MAXN];
 
int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
 
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t, n;
 
    cin >> t >> n >> a1 >> b1;
 
    for (int it = 0; it < t; it++) {
        ull ans = 0;
 
        for (int j = 0; j < n; j++) {
            arr[j] = nextRand32();
            arr1[j] = ((arr[j] << 16) >> 16);
        }
 
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < MAXN; i++) {
                c[i] = 0;
                h[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                c[arr1[i]]++;
            }
 
            int pointer = 0;
 
            for (int i = 0; i < MAXN; i++) {
                h[i] = pointer;
                pointer += c[i];
            }
            for (int i = 0; i < n; i++) {
                r[h[arr1[i]]++] = arr[i];
            }
            for (int i = 0; i < n; i++) {
                arr[i] = r[i];
                arr1[i] = (arr[i] >> 16);
            }
        }
 
        for (int j = 0; j < n; j++) {
            ans += (ull(arr[j]) * ull(j + 1));
        }
 
        cout << ans << endl;
    }
 
    return 0;
}
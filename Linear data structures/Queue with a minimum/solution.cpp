#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <malloc.h>
#include <stdlib.h>
 
using namespace std;
 
struct vector {
    int size, capacity;
    pair<int, int> *arr;
};
 
void init(vector &a) {
    a.size = 0;
    a.capacity = 1;
    a.arr = (pair<int, int>*)malloc(1 * sizeof(pair<int, int>));
}
 
void increase(vector &a) {
    a.capacity *= 2;
    pair<int, int> *new_array = (pair<int, int>*)malloc(a.capacity * sizeof(pair<int, int>));
 
    for (int i = 0; i < a.size; i++) {
        new_array[i] = a.arr[i];
    }
 
    free(a.arr);
    a.arr = new_array;
}
 
void decrease(vector &a) {
    a.capacity /= 2;
    pair<int, int> *new_array = (pair<int, int>*)malloc(a.capacity * sizeof(pair<int, int>));
 
    for (int i = 0; i < a.size; i++) {
        new_array[i] = a.arr[i];
    }
 
    free(a.arr);
    a.arr = new_array;
}
 
void check(vector &a) {
    if (a.size == a.capacity) {
        increase(a);
    }
    if (4 * a.size == a.capacity) {
        decrease(a);
    }
}
 
void transpose(vector &a1, vector &a2) {
    for (int i = a1.size - 1; i >= 0; i--) {
        if (a2.size > 0) {
            a2.arr[a2.size].second = min(a1.arr[i].first, a2.arr[a2.size - 1].second);
        }
        else {
            a2.arr[a2.size].second = a1.arr[i].first;
        }
 
        a2.arr[a2.size++].first = a1.arr[i].first;
        check(a2);
    }
 
    free(a1.arr);
    a1.capacity = 1;
    a1.size = 0;
    a1.arr = (pair<int, int>*)malloc(1 * sizeof(pair<int, int>));
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, m, k, a, b, c, last = 0, last1 = 0, last2 = 0;
    long long sum = 0;
    vector stack1, stack2;
 
    cin >> n >> m >> k >> a >> b >> c;
 
    init(stack1);
    init(stack2);
 
    for (int i = 0; i < n; i++) {
        if (i < k) {
            cin >> stack1.arr[stack1.size++].first;
        }
        else {
            stack1.arr[stack1.size++].first = a * last2 + b * last1 + c;
        }
 
        if (stack1.size > 1) {
            stack1.arr[stack1.size - 1].second = min(stack1.arr[stack1.size - 2].second, stack1.arr[stack1.size - 1].first);
        }
        else {
            stack1.arr[stack1.size - 1].second = stack1.arr[stack1.size - 1].first;
        }
 
        check(stack1);
 
        last = stack1.arr[stack1.size - 1].first;
 
        if (i >= m - 1) {
            if (stack2.size == 0) {
                transpose(stack1, stack2);
            }
 
            if (stack1.size >= 1) {
                sum += min(stack2.arr[--stack2.size].second, stack1.arr[stack1.size - 1].second);
            }
            else {
                sum += stack2.arr[--stack2.size].second;
            }
        }
 
        check(stack2);
 
        last2 = last1;
        last1 = last;
    }
 
    cout << sum;
 
    return 0;
}
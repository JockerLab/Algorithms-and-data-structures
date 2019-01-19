#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <malloc.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
 
struct vector {
    int size, capacity, *arr;
};
 
void init(vector &a) {
    a.size = 0;
    a.capacity = 1;
    a.arr = (int*)malloc(1 * sizeof(int));
}
 
void increase(vector &a) {
    a.capacity *= 2;
    int *new_array = (int*)malloc(a.capacity * sizeof(int));
 
    for (int i = 0; i < a.size; i++) {
        new_array[i] = a.arr[i];
    }
 
    free(a.arr);
    a.arr = new_array;
}
 
void decrease(vector &a) {
    a.capacity /= 2;
    int *new_array = (int*)malloc(a.capacity * sizeof(int));
 
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
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int m;
    char c;
    vector stack;
 
    init(stack);
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> c;
 
        if (c == '+') {
            cin >> stack.arr[stack.size++];
        }
        if (c == '-') {
            cout << stack.arr[--stack.size] << endl;
        }
        check(stack);
    }
 
    return 0;
}
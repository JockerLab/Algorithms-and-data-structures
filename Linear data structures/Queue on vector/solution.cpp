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
 
void transpose(vector &a1, vector &a2) {
    for (int i = a1.size - 1; i >= 0; i--) {
        a2.arr[a2.size++] = a1.arr[i];
        check(a2);
    }
 
    free(a1.arr);
    a1.capacity = 1;
    a1.size = 0;
    a1.arr = (int*)malloc(1 * sizeof(int));
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int m;
    char c;
    vector stack1, stack2;
 
    init(stack1);
    init(stack2);
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> c;
 
        if (c == '+') {
            cin >> stack1.arr[stack1.size++];
        }
        if (c == '-') {
            if (stack2.size <= 0) {
                stack2.size = 0;
                transpose(stack1, stack2);
            }
 
            cout << stack2.arr[--stack2.size] << endl;
        }
 
        check(stack1);
        check(stack2);
    }
 
    return 0;
}
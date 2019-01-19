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
     
    int num = 0;
    bool flag = 0;
    string s;
    vector stack;
 
    init(stack);
 
    while (cin >> s) {
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = (num * 10) + (s[i] - '0');
                flag = 1;
                continue;
            }
        }
        if (s == "+") {
            stack.arr[stack.size - 2] = stack.arr[stack.size - 2] + stack.arr[stack.size - 1];
            stack.size--;
        }
        if (s == "-") {
            stack.arr[stack.size - 2] = stack.arr[stack.size - 2] - stack.arr[stack.size - 1];
            stack.size--;
        }
        if (s == "*") {
            stack.arr[stack.size - 2] = stack.arr[stack.size - 2] * stack.arr[stack.size - 1];
            stack.size--;
        }
        if (flag) {
            stack.arr[stack.size++] = num;
            num = 0;
            flag = 0;
        }
 
        check(stack);
    }
 
    cout << stack.arr[--stack.size];
 
    return 0;
}
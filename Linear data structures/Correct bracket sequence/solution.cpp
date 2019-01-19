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
    int size, capacity;
    char *arr;
};
 
void init(vector &a) {
    a.size = 0;
    a.capacity = 1;
    a.arr = (char*)malloc(1 * sizeof(char));
}
 
void increase(vector &a) {
    a.capacity *= 2;
    char *new_array = (char*)malloc(a.capacity * sizeof(char));
 
    for (int i = 0; i < a.size; i++) {
        new_array[i] = a.arr[i];
    }
 
    free(a.arr);
    a.arr = new_array;
}
 
void decrease(vector &a) {
    a.capacity /= 2;
    char *new_array = (char*)malloc(a.capacity * sizeof(char));
 
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
     
    string s;
    vector stack;
 
    init(stack);
 
    while (cin >> s) {
        bool flag = 0;
 
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] == ']' || s[i] == ')') {
                if (stack.size == 0) {
                    flag = 1;
                    break;
                }
                if ((stack.arr[stack.size - 1] == '[' && s[i] == ']') || (stack.arr[stack.size - 1] == '(' && s[i] == ')')) {
                    stack.size--;
                    continue;
                }
 
                flag = 1;
                break;
            } 
            else {
                stack.arr[stack.size++] = s[i];
            }
 
            check(stack);
        }
 
        if (flag || stack.size != 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
 
        free(stack.arr);
        stack.capacity = 1;
        stack.size = 0;
        stack.arr = (char*)malloc(1 * sizeof(char));
        s = "";
    }
 
    return 0;
}
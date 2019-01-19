#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <malloc.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
 
struct stack {
    int value;
    stack *next;
 
    void push(int _a) {
        stack *new_element = new stack();
        new_element->next = this->next;
        new_element->value = _a;
        this->next = new_element;
    }
    void pop() {
        stack *new_element = new stack();
        new_element = this->next->next;
        delete this->next;
        this->next = new_element;
    }
};
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    stack *head = new stack();
    int m, a;
    char c;
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> c;
 
        if (c == '+') {
            cin >> a;
 
            head->push(a);
        }
        if (c == '-') {
            cout << head->next->value << endl;
            head->pop();
        }
    }
 
    return 0;
}
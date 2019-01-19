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
        new_element->value = _a;
        this->next->next = new_element;
        this->next = new_element;
    }
    void pop() {
        this->next = this->next->next;
    }
};
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    stack *head = new stack();
    stack *tail = new stack();
    int m, a;
    char c;
 
    cin >> m;
 
    for (int i = 0; i < m; i++) {
        cin >> c;
 
        if (c == '+') {
            cin >> a;
 
            if (head->next == NULL) {
                stack *new_element = new stack();
                new_element->value = a;
                head->next = tail->next = new_element;
            } 
            else {
                tail->push(a);
            }
        }
        if (c == '-') {
            cout << head->next->value << endl;
            head->pop();
        }
    }
 
    return 0;
}
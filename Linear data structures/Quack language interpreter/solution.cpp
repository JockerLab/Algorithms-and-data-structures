#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <malloc.h>
#include <stdlib.h>
 
using namespace std;
 
template <class T>
struct vector {
    int size, capacity;
    T *arr;
 
    void push_back(T _element) {
        this->arr[this->size++] = _element;
        check();
    }
    void init(int _capacity = 1) {
        this->size = 0;
        this->capacity = _capacity;
        this->arr = new T[_capacity];
    }
    void increase() {
        this->capacity *= 2;
        T *new_array = new T[this->capacity];
 
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->arr[i];
        }
 
        delete[] this->arr;
        this->arr = new_array;
    }
    void decrease() {
        this->capacity /= 2;
        T *new_array = new T[this->capacity];
 
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->arr[i];
        }
 
        delete[] this->arr;
        this->arr = new_array;
    }
    void check() {
        if (this->size == this->capacity) {
            increase();
        }
        if (4 * this->size == this->capacity) {
            decrease();
        }
    }
    void transpose(vector<T> &a2) {
        for (int i = this->size - 1; i >= 0; i--) {
            a2.arr[a2.size++] = this->arr[i];
            a2.check();
        }
 
        delete[] this->arr;
        this->capacity = 1;
        this->size = 0;
        this->arr = new T[1];
    }
};
 
struct queue {
    vector<unsigned short> st1, st2;
 
    unsigned short front() {
        if (st2.size == 0) {
            st1.transpose(st2);
        }
        return this->st2.arr[st2.size - 1];
    }
 
    void pop() {
        if (st2.size == 0) {
            st1.transpose(st2);
        }
        this->st2.size--;
        this->st2.check();
    }
 
    void push(unsigned short _a) {
        this->st1.arr[this->st1.size++] = _a;
        this->st1.check();
    }
};
 
unsigned short translate(string s) {
    unsigned short result = (unsigned short) 0;
 
    for (int i = 0; i < int(s.size()); i++) {
        result = (unsigned short) (result * (unsigned short) 10 + (unsigned short) (s[i] - '0'));
    }
 
    return result;
}
 
vector< vector< pair<string, int> > > hashtable;
vector<long long> deg;
const int QUEUE_MOD = (1 << 16), ALPHABET = 27;
const long long HASH_MOD = 69911, HASH_DEGREE = 65537;
 
int get_hash(string s) {
    int hash = 0;
 
    for (int i = 0; i < int(s.size()); i++) {
        hash += int((s[i] * deg.arr[i]) % HASH_MOD);
        hash %= int(HASH_MOD);
    }
 
    return hash;
}
 
void set_to_hashtable(int hash, string s, int pos) {
    hashtable.arr[hash].push_back(make_pair(s, pos));
}
 
int get_from_hashtable(string s) {
    int hash = get_hash(s), ans = 0;
 
    for (int i = 0; i < hashtable.arr[hash].size; i++) {
        if (hashtable.arr[hash].arr[i].first == s) {
            ans = hashtable.arr[hash].arr[i].second;
        }
    }
 
    return ans;
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    queue q1;
    int pos = 0;
    string s;
    vector<unsigned short> reg;
    vector<string> requests;
 
    requests.init();
    deg.init(HASH_MOD);
    reg.init(ALPHABET);
    hashtable.init(HASH_MOD);
    q1.st1.init();
    q1.st2.init();
 
    deg.arr[deg.size++] = 1ll;
 
    for (int i = 1; i < HASH_MOD; i++) {
        hashtable.arr[i].init();
        deg.arr[deg.size] = (deg.arr[deg.size - 1] * HASH_DEGREE) % HASH_MOD;
        deg.size++;
    }
 
    while (cin >> s) {
        if (s[0] == ':') {
            int hash = get_hash(s.substr(1));
            set_to_hashtable(hash, s.substr(1), pos);
        }
 
        requests.push_back(s);
        pos++;
    }
 
    for (int i = 0; i < requests.size; i++) {
        s = requests.arr[i];
        if (s[0] >= '0' && s[0] <= '9') {
            q1.push(translate(s));
            continue;
        }
        if (s[0] == 'Q') {
            return 0;
        }
        if (s[0] == '+') {
            unsigned short res = (unsigned short) q1.front();
            q1.pop();
            res = (unsigned short) (res + q1.front());
            q1.pop();
            q1.push(res);
            continue;
        }
        if (s[0] == '-') {
            unsigned short res = (unsigned short) q1.front();
            q1.pop();
            res = (unsigned short) (res - q1.front());
            q1.pop();
            q1.push(res);
            continue;
        }
        if (s[0] == '*') {
            unsigned short res = (unsigned short) q1.front();
            q1.pop();
            res = (unsigned short) (res * q1.front());
            q1.pop();
            q1.push(res);
            continue;
        }
        if (s[0] == '/') {
            unsigned short res = (unsigned short) q1.front();
            q1.pop();
            if (q1.front() != 0) {
                res = (unsigned short) (res / q1.front());
            }
            else {
                res = 0;
            }
            q1.pop();
            q1.push(res);
            continue;
        }
        if (s[0] == '%') {
            unsigned short res = (unsigned short) q1.front();
            q1.pop();
            if (q1.front() != 0) {
                res = (unsigned short) (res % q1.front());
            }
            else {
                res = 0;
            }
            q1.pop();
            q1.push(res);
            continue;
        }
        if (s[0] == '>') {
            unsigned short num = q1.front();
            q1.pop();
 
            reg.arr[(s[1] - 'a')] = num;
            continue;
        }
        if (s[0] == '<') {
            q1.push(reg.arr[(s[1] - 'a')]);
            continue;
        }
        if (s == "P") {
            unsigned short num = q1.front();
            q1.pop();
 
            cout << num << endl;
            continue;
        }
        if (s[0] == 'P') {
            cout << reg.arr[(s[1] - 'a')] << endl;
            continue;
        }
        if (s == "C") {
            unsigned short num = q1.front();
            q1.pop();
 
            cout << char(num % 256);
            continue;
        }
        if (s[0] == 'C') {
            cout << char(reg.arr[(s[1] - 'a')] % 256);
            continue;
        }
        if (s[0] == ':') {
            continue;
        }
        if (s[0] == 'J') {
            int id = get_from_hashtable(s.substr(1));
            i = id;
            continue;
        }
        if (s[0] == 'Z') {
            if (reg.arr[(s[1] - 'a')] == 0) {
                int id = get_from_hashtable(s.substr(2));
                i = id;
            }
            continue;
        }
        if (s[0] == 'E') {
            if (reg.arr[(s[1] - 'a')] == reg.arr[(s[2] - 'a')]) {
                int id = get_from_hashtable(s.substr(3));
                i = id;
            }
            continue;
        }
        if (s[0] == 'G') {
            if (reg.arr[(s[1] - 'a')] > reg.arr[(s[2] - 'a')]) {
                int id = get_from_hashtable(s.substr(3));
                i = id;
            }
            continue;
        }
    }
 
    return 0;
}
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
vector<int> requests, deleted;
vector< pair<int, int> > value;
 
void push(int pos) {
    while (pos > 0 && value[pos].first < value[(pos - 1) / 2].first) {
        requests[value[pos].second] = (pos - 1) / 2;
        requests[value[(pos - 1) / 2].second] = pos;
        swap(value[pos], value[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}
 
void extract_min() {
    if (sz(value) == 0) {
        cout << "*" << endl;
        return;
    } else {
        cout << value[0].first << " " << value[0].second + 1 << endl;
    }
 
    requests[value[0].second] = sz(value) - 1;
    requests[value[sz(value) - 1].second] = 0;
    deleted[value[0].second] = 1;
    swap(value[0], value[sz(value) - 1]);
    value.pop_back();
 
    if (sz(value) == 0) {
        return;
    }
 
    int pos = 0, p = value[0].first, c1 = 2e9, c2 = 2e9;
 
    if (sz(value) > 1) {
        c1 = value[1].first;
    }
    if (sz(value) > 2) {
        c2 = value[2].first;
    }
 
    while (pos < sz(value) && (p > c1 || p > c2)) {
        if (c1 < c2 && c1 < p) {
            requests[value[pos].second] = pos * 2 + 1;
            requests[value[pos * 2 + 1].second] = pos;
            swap(value[pos], value[pos * 2 + 1]);
            pos = pos * 2 + 1;
        } else {
            requests[value[pos].second] = pos * 2 + 2;
            requests[value[pos * 2 + 2].second] = pos;
            swap(value[pos], value[pos * 2 + 2]);
            pos = pos * 2 + 2;
        }
 
        if (pos < sz(value)) {
            p = value[pos].first;
 
            if (pos * 2 + 1 < sz(value)) {
                c1 = value[pos * 2 + 1].first;
            } else {
                c1 = 2e9;
                c2 = 2e9;
            }
 
            if (pos * 2 + 2 < sz(value)) {
                c2 = value[pos * 2 + 2].first;
            } else {
                c2 = 2e9;
            }
        }
    }
}
 
void decrease_key(int id_request, int x) {
    if (deleted[id_request] == 1) {
        return;
    }
 
    value[requests[id_request]].first = x;
    int pos = requests[id_request];
 
    while (pos > 0 && value[pos].first < value[(pos - 1) / 2].first) {
        requests[value[pos].second] = (pos - 1) / 2;
        requests[value[(pos - 1) / 2].second] = pos;
        swap(value[pos], value[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    string q;
    int a, b, cnt = 0;
 
    while (cin >> q) {
        if (q == "push") {
            cin >> a;
 
            value.push_back(make_pair(a, cnt));
            requests.push_back(sz(value) - 1);
            deleted.push_back(0);
            push(sz(value) - 1);
        }
        if (q == "extract-min") {
            requests.push_back(-1);
            deleted.push_back(0);
 
            extract_min();
        }
        if (q == "decrease-key") {
            requests.push_back(-1);
            deleted.push_back(0);
 
            cin >> a >> b;
 
            decrease_key(a - 1, b);
        }
        cnt++;
    }
 
    return 0;
}
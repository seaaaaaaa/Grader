#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n,m;
    cin >> n >>m;
    set<int>  v1 ,v2;
    set<int> r;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        v1.insert(c);
    }
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        v2.insert(c);
    }
    for (auto &x : v1) {
        if (v2.find(x) != v2.end()) {
            r.insert(x);
        }
    }
    for (auto &x : r) {
        cout << x << " ";
    }
    
    return 0;
}
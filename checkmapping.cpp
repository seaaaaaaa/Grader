#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        s.insert(m);
    }
    vector<int> v;
    for (int i=1; i<=n; i++) {
        v.push_back(i);
    }
    bool p=false;
    set<int> vs(v.begin(), v.end());
    if (s == vs) {
        p=true;
    }
    if (p) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
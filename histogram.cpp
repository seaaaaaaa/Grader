#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string,int> a;
    for (int i=0;i<n;i++) {
        string s;
        cin >> s;
        a[s]++;

    }
    for (auto p:a) {
        if (p.second > 1) {
        cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
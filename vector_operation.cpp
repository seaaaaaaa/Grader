#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;    
int main() {
    vector<int> a;
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n
    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);
        stringstream ss(x);
        string cmd;
        ss >> cmd;
        if (cmd == "pb") {
            int num;
            if (ss >> num) {
                a.push_back(num);
            }
        }
        else if (cmd == "sa") {
            sort(a.begin(), a.end());
        }
        else if (cmd == "sd") {
            sort(a.begin(), a.end(), greater<int>());
        }
        else if (cmd == "r") {
            reverse(a.begin(), a.end());
        }
        else if (cmd == "d") {
            int idx;
            if (ss >> idx) {
                if (idx >= 0 && idx < a.size()) {
                    a.erase(a.begin() + idx);
                }
            }
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) {
            cout << " ";
        }
    }
}
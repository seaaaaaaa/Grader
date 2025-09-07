#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,l;
    cin >> n >> m >> l;
    vector<int> sn;
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        sn.push_back(x%26);
    }
    set<string> p1;
    for (int i=0;i<n;i++) {
        string p;
        cin >> p;
        p1.insert(p);
    }
    for (int i=0;i<m;i++) {
        string password;
        cin >> password;
        int count=0;
        string new_password;
        for (auto c: password) {
            char new_c;
            new_password+= 'a' + (c - 'a' + sn[count]) % 26;
            count++;
        }
        if (p1.find(new_password)!=p1.end()) {
            cout << "Match\n";
        } else {
            cout << "Unknown\n";
        }
        
    }

}
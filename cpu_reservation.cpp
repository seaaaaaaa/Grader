#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<pair<int, int>> s;
    int round = 1;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        bool overlap = false;
        auto it1 = s.lower_bound({a,b});
        if (s.empty()) {
            cout << round << " ";
            s.insert({a,b});
            round++;
            continue;
        } else {
            if (it1 == s.end()) {
                auto it2 = prev(it1);
                if (it2->second >= a) {
                    overlap = true;
                }
            } else if (it1 == s.begin()) {
                if (it1->first <= b) {
                    overlap = true;
                }
            } else {
                auto it2 = prev(it1);
                if (it1->first <= b || it2->second >= a) {
                    overlap = true;
                }
            }
            if(!overlap) {
                cout << round << " ";
                s.insert({a,b});
            }

        /*if (it1 != s.begin()|| it1 != s.end()) {
            auto it2 = prev(it1);
            if (it1->first <= b || it2->second >= a) {
                overlap = true;
            } 
        } else {
            if (it1->first <= b) {
                overlap = true;
            }
        }
        if(!overlap) {
            cout << round << " ";
            s.insert({a,b});
        }
            */
            round++;
        }   
    }
}
        

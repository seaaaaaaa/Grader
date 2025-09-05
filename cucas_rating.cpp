#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
int main() {
    cout << std::fixed << std::setprecision(2);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map <string,pair<int,int>> s,t;
    for (int i=0;i<n;i++) {
        string course,teacher;
        double r;
        cin >> course >> teacher >> r;
        if (s.find(course)==s.end()) {
            s[course]={r,1};
        } else {
            s[course].first+=r;
            s[course].second++;
        }
        if (t.find(teacher)==t.end()) {
            t[teacher]={r,1};
        } else {
            t[teacher].first+=r;
            t[teacher].second++;
        }
    }
    for (auto p :s) {
        cout << p.first << " " << (p.second.first+0.0)/p.second.second << endl;
    }
    for (auto p :t) {
        cout << p.first << " " << (p.second.first+0.0)/p.second.second << endl;
    }
}
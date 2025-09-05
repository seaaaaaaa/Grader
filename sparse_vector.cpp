#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
 //your code here
    auto tail_begin = v.lower_bound(pos);
    vector<pair<int,int>> tail;
    tail.reserve(distance(tail_begin,v.end()));
    for (auto it=tail_begin;it!=v.end();++it) {
        tail.push_back({it->first+1,it->second});
    }
    v.erase(tail_begin,v.end());
    v.insert(v.end(),{pos,value});
    for (const auto &p : tail) {
        v.insert(v.end(),p);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}
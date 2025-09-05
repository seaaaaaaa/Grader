#include <iostream> 
#include <vector> 
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    map <string,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if (m.find(s)!=m.end()) {
        m[s]++;
        } else {
            m[s]=1;
        }
    }
    vector<int> v;
    for (auto p:m) {
        if (p.second >0) v.push_back(p.second);
    }
    sort(v.begin(),v.end(),greater<int>());
    if (v.size() > k) {
        cout << v[k-1] << endl;
    } else {
        cout << v.back() << endl;
    }
}    
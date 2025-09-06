#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n,M;
    cin >> n >> M;
    map<int,pair<int,int>> m;
    for (int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        m[a]={a,b};
    }
    for (int i=0;i<M;i++) {
        int x;
        cin >> x;
        if (x<m.begin()->first) cout << 0 << " ";
        else{
            auto it = m.upper_bound(x);
            it--;
            if (x>=it->second.first && x<=it->second.second) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        } 
    }
}
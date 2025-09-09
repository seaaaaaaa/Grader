#include <iostream>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >>m;
    set<int> product;
    map<int,int> s ;
    set<pair<int,int>> sr;
    for (int i=0;i<n;i++) {
        int y;
        cin >> y;
        product.insert(y);
    }
    for (int i=0;i<m;i++){
        int o;
        cin >> o;
        if (o==1) {
            int a,b;
            cin >> a >> b;
            if (product.find(a)!=product.end()){
                if(sr.find({s[a],a})!=sr.end()) {
                    sr.erase({s[a],a});
                }
                s[a]+=b;
                sr.insert({s[a],a});
            }
        } else if (o==2){
            int k;
            cin >> k;
            auto it =sr.lower_bound({k,0});
            if (it == sr.begin()) {
                cout << "NONE" << "\n";
            } else {
                it--;
                cout << it->second << "\n";
            }
        }
    }
}
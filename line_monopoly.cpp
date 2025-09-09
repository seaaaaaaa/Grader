#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<pair<int,int>> s;
    
    for (int i =0;i<n;i++) {
        int o;
        cin >> o;
        if (o==1){
            int start,end;
            cin >> start >> end;
            s.insert(make_pair(start,end));
            

        }
        if (o==2) {
            set<pair<int,int>> r;
            pair<int,int> result=*s.begin();
            for (auto it = next(s.begin());it != s.end();it++) {
                if ((it->first-result.second)>1) {
                    r.insert(result);
                    result = *it;
                } else {
                    result = make_pair(result.first,max(it->second,result.second));
                }
                
            }
            r.insert(result);
            cout << "\n";
            cout  << r.size()<<endl;
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    map<int,vector<pair<int,int>>> m;
    int q;
    cin >> q;
    int v=0;
    for(int i=0;i<q;i++){
        string o;
        cin >> o;
        if(o=="U"){
            v++;
            int pos,val;
            cin >> pos >> val;
            m[pos].push_back(make_pair,val); 
        }
        if(o=="A"){
            int pos,ver;
            cin >> pos >> ver;
            if(m.find(pos)==m.end()||ver==0){
                cout << -1 << "\n";
            
            } else {
                vector<pair<int,int>> vec = m[pos];
                auto it = lower_bound(vec.begin(),vec.end(),make_pair(ver+1,-1));
                
                if(it==vec.begin()){
                    cout << -1 << "\n";
                } else {
                    it--;
                    cout << it->second << "\n";
                }    
            }
        }
    }
}


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <iterator>
using namespace std;

bool connect(list<int> &l, list<int>::iterator &it , int v){
    int count = 1;
    auto start = it;
    auto end = next(it,1);
    while(end != l.end() && *end == v){
        count++;
        end++;
    }
    while(start != l.begin() && *prev(start,1) == v){
        count++;
        start--;
    }
    if(count>=3){
        it = l.erase(next(start,1),end);
        return true;
    } else {
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k,v;
    cin >> n >> k >> v;
    list<int> l;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        l.push_back(x);
    }
    auto it = next(l.begin(),k);
    it = l.insert(it,v);
    bool c = connect(l,it,v);
    while(c){
        // Keep connecting until no more connections can be made
        it--;
        if(it!=l.end()){
            c = connect(l,it,*it);
        } else {
            break;
        }
    }
    for(auto &x : l){
        cout << x << " ";
    }
}
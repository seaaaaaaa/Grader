#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >>k;
    map<int,int> e,er;
    e[0]=k;
    er[k]=0;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i=0; i<n ; i++){
        int event,time;
        cin >> event >> time ;
        pq.push({event,time});
    }
    for (int i=0; i<n; i++) {
        int ev,t;
        //cout << ev << " " << t <<"\n";
        ev=pq.top().first;
        t=pq.top().second;
        pq.pop();
        k-=t;
        if (k<0) k=0;
        e[ev]=k;
        er[k]=ev;
        if (k==0) break;
    }/*?*for (auto x:e){
        cout << x.first << " " << x.second << " ";
    }
    for (auto y:er){
        cout << y.first << " " << y.second << " ";
    } */
    for (int i=0;i<m;i++) {
        int a,q;
        cin >> a >> q;
        if (a==1) {
            auto it = e.upper_bound(q) ;
            it--;
            cout << it->second << "\n";
        } else {
            auto it = er.lower_bound(q);
            it--;
            cout << (it->second)  << "\n";
        }
    } 
    return 0;

}
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
    for (int i=0; i<n ; i++){
        int event,time;
        cin >> event >> time ;
        k-= time;
        if (k<=0) {
            k=0;
        }
        e[event]=k;
        er[k]=event;
        if (k==0) break;
    }
    for (int i=0;i<m;i++) {
        int a,q;
        cin >> a >> q;
        if (a==1) {
            auto it = upper_bound(e.begin(),e.end(),q) ;
            it--;
            cout << it->second << "\n";
        } else {
            auto it = lower_bound(er.begin(),er.end(),q);
            cout << (it->second) +1 << "\n";
        }
    }
    return 0;

}
#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
#include <sstream>
#include <cstdio>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ostringstream out;
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i=0;i<n;i++){
        int x;
        int y;
        scanf("%d %d",&x,&y);
        pq.push({x,y});
    }
    
    vector<int> s;
    
    for (int i=0;i<n;i++){
        for (int i=s.size();i<pq.top().first;i++){
            s.push_back(k);
        }
        int a = pq.top().second;
        pq.pop();
        k -= a;
        if (k<0) k=0;
        s.push_back(k);
    }
    /*for (auto j: s){
        cout << j << " ";
    } */
    
    vector<int> ss=s;
    sort(ss.begin(),ss.end());
    vector<int> r;
    for (int i=0;i<m;i++) {
        int q,t;
        scanf("%d %d",&q,&t);
        if (q==1){
            //cout << s[t] << endl;
            out << s[t] << "\n";
        }
        if (q==2) {
            int result;
            result = ss.size()-(lower_bound(ss.begin(),ss.end(),t)-ss.begin());
            if (result<0) result =0;
            //cout << result << endl;
            out << result << "\n";
        }
        
    }
    
    cout << out.str();
}
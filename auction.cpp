#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main() {
    int n,m,a;
    cin >> n >> m >> a;
    vector<int> v(n);
    for (int i =0;i<n;i++) {
        cin >> v[i];
    }
    vector<map<int,int>> bids(n);
    for (int i=0;i<a;i++) {
        char o;
        cin >> o;
        if(o=='B'){
            int u,i,v;
            cin >> u >> i >> v;
            bids[i-1][u]=v;
        }
        else if(o=='W') {
            int u,i;
            cin >> u >> i;
            if (bids[i-1].find(u)!=bids[i-1].end()) {
                bids[i-1].erase(u);
            }
        }
    }
    queue<priority_queue<pair<int,int>>> q;
    for (int i=0;i<n;i++) {
        priority_queue<pair<int,int>> pq;
        for (auto it=bids[i].begin();it!=bids[i].end();it++) {
            pq.push(make_pair(it->second,it->first));
        }
        q.push(pq);
    }
    vector<queue<int>> result(m);
    int item=1;
    for (auto x : v) {
        if (q.empty()) {
            break;
        } else if (q.front().empty()) {
            q.pop();
            item++;
            continue;
        } else{
            priority_queue<pair<int,int>> win=q.front();
            q.pop();
            for (int i =0;i<x;i++) {
                if (win.empty()) {
                break; // Stop if there are no more bidders
                }
                result[win.top().second - 1].push(item);
                win.pop();
            }
        }
        item++;
    }
    for (auto &y:result) {
        if (y.empty()) {
            cout << "NONE\n";
        } else {
            while(!y.empty()) {
                cout << y.front() << " ";
                y.pop();
            }
            cout << "\n";
        }
    }
}
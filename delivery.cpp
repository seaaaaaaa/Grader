#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,M;
    cin >> n >> M;
    queue<int> q;
    map<int,int> m;
    set<int> s;
    int income=0;
    int round=0;
    queue<int> q1,q2;
    for (int i=0;i<M;i++) {
        int x;
        cin >> x;
        q.push(x);
        s.insert(x);
    }
    for (int i=0; i<n; i++) {
        int o;
        cin >> o;

        if (o==1) {
            int r,p;
            cin >> r >> p;
            if (r==1) {
                q1.push(p);
            }
            if (r==2) {
                q2.push(p);
            }
        }   
        if (o==2) {
            if (q1.empty() && q2.empty()) {
        // nothing to process, skip this operation
                continue;
            }

            int order;
            if (q1.empty()) {
                order = q2.front();
                q2.pop();
            } else if (q2.empty()) {
                order = q1.front();
                q1.pop();
            } else {
                if (q1.front() == q2.front()) {
                    order = q1.front();
                    q1.pop();
                } else if (q1.front() < q2.front()) {
                    order = q1.front();
                    q1.pop();
                } else {
                    order = q2.front();
                    q2.pop();
                }
            }

            round++;
            income += order;
            auto it = s.upper_bound(income);
            auto j = s.begin();
            while (j != it) {
                m[*j] = round;
                j = s.erase(j); // erase() returns the next valid iterator
            }
        }
        
        
        
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if (m.find(x)==m.end()) {
            cout << -1 << " ";
        } else {
            cout << m[x] << " ";
        }
    }
}
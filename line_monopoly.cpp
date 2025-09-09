#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> s;
    
    for (int i =0;i<n;i++) {
        int o;
        cin >> o;
        if (o==1){
            int start,end;
            cin >> start >> end;
            s.push(make_pair(start,end));
        }
        else if (o==2) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> r;
            pair<int,int> result=s.top();
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> s1=s;
            while(!s1.empty()){
                pair<int,int> temp=s1.top();
                if (temp.first-result.second>1){
                    r.push(result);
                    result=temp;
                } else {
                    result.second=max(result.second,temp.second);
                }
                s1.pop();
            }
            r.push(result);
            cout  << r.size()<<endl;
        }
    }
}
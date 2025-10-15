#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
void dfs(int node,int n,vector<int> &result){
    if(node>=n) return;
    result.push_back(node);

    int left_child = 2*node+1;
    dfs(left_child,n,result);

    int right_child = 2*node+2;
    dfs(right_child,n,result);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        vector<int> descendants;
        if(a==b){
            cout << " a and b are the same node\n";
            continue;
        }
        int f = min(a,b);
        string a1, a2;
        if(f==a){
            a1 = "a";
            a2 = "b";
        }
        else {
            a1 = "b";
            a2 = "a";
        }
        dfs(f,n,descendants);
        sort(descendants.begin(),descendants.end());
        if(find(descendants.begin(),descendants.end(),max(a,b))!=descendants.end()){
            cout << a1 + " is an ancestor of " + a2 << "\n";
        } else {
            cout << "a and b are not related\n";
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void dfs(int node,int n,set<int> &result){
    if(node>=n) return;
    result.insert(node);

    int left_child = 2*node+1;
    dfs(left_child,n,result);

    int right_child = 2*node+2;
    dfs(right_child,n,result);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,a;
    cin >> n >> a;
    set<int> descendants;
    dfs(a,n,descendants);
    cout << n - descendants.size() << "\n";
    for(int i=0;i<n;i++){
        if(descendants.find(i)==descendants.end()){
            cout << i << " ";
        }
    }

}
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void dfs(int node,int n,vector<int> &result){
    if(node>=n) return;
    result.push_back(node);

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
    vector<int> descendants;
    dfs(a,n,descendants);
    sort(descendants.begin(),descendants.end());
    cout << descendants.size() << "\n";
    for(int i=0;i<descendants.size();i++){
        cout << descendants[i] << " ";
    }
    
}


    
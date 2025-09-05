#include <iostream> 
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> c;
    for (int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        c.push_back({a,b});
    } 
    sort(c.begin(),c.end());
    for (int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        pair<int,int> k = {x,y};
        if (k<c[0]){
            //cout << c[0].first<<" "<<c[0].second<< " ";
            cout << -1 << " " << -1 << " ";
        } else {
            auto it= lower_bound(c.begin(),c.end(),k);
            if (k==*it){
                cout << 0 << " " << 0 << " ";
            } else {
            cout << (it-1)->first << " " << (it-1)->second << " ";
            }
        }
    }
}
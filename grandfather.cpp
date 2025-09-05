#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<long long, long long> k;
    for (int i = 0; i<n; i++) {
        long long x,y;
        cin >> x >> y;
        k[y]=x;

    }
    for (int i=0;i<m;i++) {
        long long a,b;
        cin >> a >> b;
        if(a==b){
            cout << "NO" << endl;
            continue;
        }
        if (k.find(a) == k.end() || k.find(b) == k.end()) {
            cout << "NO" << endl;
            continue;
        }
        if (k.find(k[a]) == k.end() || k.find(k[b]) == k.end()) {
            cout << "NO" << endl;
            continue;
        } 
        if (k[k[a]] == k[k[b]]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

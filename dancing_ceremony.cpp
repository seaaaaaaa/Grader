#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n),b(n);
    long long f = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    vector<long long> r;
    for (int i=0;i<n;i++) {
        int q = a[i] - b[i];
        r.push_back(q);
    }
    
    
    sort(r.begin(),r.end());
    for (int i=0;i<n-1;i++) {
        long long x = upper_bound(r.begin()+i+1,r.end(),-r[i]) - r.begin();
        f += n - x;
    }
    cout << f;
}
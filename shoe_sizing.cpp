#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    while(m--) {
        long long x;
        cin >> x;
        if (a.size() == 1) {
            cout << a[0] << " ";
        } else{
            auto it = lower_bound(a.begin(),a.end(),x);
            if (it == a.end()) {
                cout << a.back() << " ";
            } else if(it==a.begin()) {
                 cout << a.front() << " ";
            }else {
                if (abs(x - *it) <= abs(x - *(it - 1))) {
                    cout << *it << " ";
                } else {
                    cout << *(it-1) << " ";
                }
            }
        }
    }
}
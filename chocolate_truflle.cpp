#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long r,c,k;
    cin >> r >> c >> k;
    vector<long long> v;
    for (int i=0; i<k; i++) {
        long long k1,k2;
        cin >> k1 >> k2;
        long long pos = (k1-1)*c + k2;
        v.push_back(pos);
    }
    sort(v.begin(), v.end());
    

    
    long long q;
    cin >> q;
    for (int i=0; i<q; i++) {
        long long q1,q2;
        cin >> q1 >> q2;
        long long pos = (q1-1)*c + q2;
        auto it = lower_bound(v.begin(), v.end(), pos);
        if (it != v.end()) {
            cout << *it - pos << endl;
        } else {
            auto it2 = lower_bound(v.begin(), v.end(), 0);
            cout << *it2 + r*c - pos << endl;
        }

    }
    return 0;

}
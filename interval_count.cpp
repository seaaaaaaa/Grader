#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        int p; 
        cin >> p;
        int L = p - k;
        int R = p + k;
        auto itL = lower_bound(a.begin(), a.end(), L);
        auto itR = upper_bound(a.begin(), a.end(), R);
        cout << (itR - itL) << " ";
    }
    return 0;
}

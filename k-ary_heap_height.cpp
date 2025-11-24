#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    if(k==1) {
        cout << n-1 << endl;
        return 0;
    }
    long long height = 0;
    long long node_cap = 0;
    while(node_cap < n) {
        node_cap += pow(k, height);
        height++;
    }
    cout << height - 1 << endl;
}

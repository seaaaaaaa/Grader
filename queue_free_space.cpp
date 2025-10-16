#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long mSize = 0;
    long long mCap = 1;
    long long maxSize = 0;
    for (long long i = 0; i<n; i++) {
        long long o,m;
        cin >> o >> m;
        if (o == 0) {
            mSize += m;
        } else {
            mSize -= m;
        }
        maxSize = max(maxSize, mSize);
        
    }
    while(maxSize > mCap) {
        mCap *= 2;
    }
    cout << mCap - mSize << "\n";
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<int> Q(M);
    for (int i = 0; i < M; i++) cin >> Q[i];
    
    
    sort(A.begin(), A.end());
    
    for (int q : Q) {
        int l = 0, r = N - 1;
        bool found = false;
        while (l < r) {
            int sum = A[l] + A[r];
            if (sum == q) {
                found = true;
                break;
            }
            if (sum < q) l++;
            else r--;
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

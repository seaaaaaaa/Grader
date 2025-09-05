#include <iostream>
#include <vector>
#include <climits>   // for INT_MIN
#include <algorithm> // for max

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int R;
    cin >> R;

    vector<vector<int>> mat(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
        }
    }

    

    while (R--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // Check invalid case
        if (r1 > r2 || c1 > c2) {
            cout << "INVALID" << endl;
            continue;
        }

        // Clip coordinates to matrix boundaries
        int rr1 = max(r1, 1);
        int cc1 = max(c1, 1);
        int rr2 = min(r2, N);
        int cc2 = min(c2, M);

        // Check if region is outside
        if (rr1 > N || cc1 > M || rr2 < 1 || cc2 < 1) {
            cout << "OUTSIDE" << endl;
            continue;
        }

        // If after clipping region is empty, it’s outside
        if (rr1 > rr2 || cc1 > cc2) {
            cout << "OUTSIDE" << endl;
            continue;
        }

        // Find max inside region
        int mx = INT_MIN;
        for (int i = rr1 - 1; i < rr2; i++) {
            for (int j = cc1 - 1; j < cc2; j++) {
                mx = max(mx, mat[i][j]);
            }
        }

        cout << mx << endl;
    }

    return 0;
}

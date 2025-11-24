#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        bool is_valid = true;
        int n,k;
        cin >> n >> k;
        vector<int> mData;
        for(int j = 0; j<n ; j++) {
            int val;
            cin >> val;
            mData.push_back(val);
        }
        for(int j = 0 ;j<n;j++){
            int p = (j - 1) / k;
            if(mData[p] < mData[j] && j != 0){
                is_valid = false;
                break;
            }
        }
        if(is_valid) cout << "true" << endl;
        else cout << "false" << endl;
    }
}
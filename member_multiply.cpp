#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator,int>> &multiply) {
 //write your code here
    // Convert iterators to indices
    vector<pair<int,int>> idx;
    idx.reserve(multiply.size());
    for (auto &p : multiply) {
        idx.push_back({(int)(p.first - v.begin()), p.second});
    }

    // Sort by index
    sort(idx.begin(), idx.end());

    // Build new vector
    vector<int> result;
    result.reserve(1000000); // max size constraint

    int n = v.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        result.push_back(v[i]);  // always original element
        if (j < idx.size() && idx[j].first == i) {
            for (int k = 0; k < idx[j].second; k++) {
                result.push_back(v[i]);
            }
            j++;
        }
    }
    v.swap(result);
}
    

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }

    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
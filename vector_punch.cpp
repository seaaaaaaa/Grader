#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    int start;
    int stop;
    int pos;
    vector<string> a;
    for (int i=0; i < v.size(); i++) {
        if (v[i] == *it) {
            pos = i;
            break;
        }
    }
    if (pos-k < 0) {
        start = 0;
    } else {
        start = pos - k;
    }
    if (pos + k >= v.size()) {
        stop = v.size() - 1;
    } else {
        stop = pos + k;
    }
    for(int i = 0; i < start; i++) {
        a.push_back(v[i]);
    }
    for(int i=stop+1; i<v.size(); i++) {
        a.push_back(v[i]);
    }
    return a;

 //write some code here
 //don’t forget to return something
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
 }
}
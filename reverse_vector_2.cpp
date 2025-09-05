#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
 //write your code only in this function
    vector<int> s;

    if (a == b-1) {
        
        return; // If a and b are the same, no need to reverse
    } // If a and b are the same, no need to reverse
    else{
        for (auto it = a; it <= b-1; ++it) {
            s.push_back(*it);
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            *a = s[i];
            ++a;
        }
        
    }

}
int main() {
 //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
 //call function
    reverse(v,v.begin()+a,v.begin()+b+1);
 //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
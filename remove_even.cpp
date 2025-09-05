#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v,int a,int b) {
 //write your code only in this function
    int e = 0;
    for (int i=0; i < v.size(); i++) {
        if (e%2 == 0){
            if ( i % 2 == 0 && i >= a && i <= b) {
                v.erase(v.begin() + (i));
                
                i--;
                e++;
                b--;
                
            }
        }
        else if (e%2 == 1) {
            if (i % 2 == 1 && i >= a && i <= b) {
                v.erase(v.begin() + (i));
                
                i--;
                e++;
                b--;
            }
        }
        //cout << "i: " << i << " e: " << e << " v.size(): " << v.size() << endl;
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
    remove_even(v,a,b);
 //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
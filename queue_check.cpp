#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<string> result;
    for (int i = 0;i < n;i++) {
        int f,s,cap,l,c;
        cin >> f >> s >> cap >> l >> c;
        string q = "";
        
        if (s <= cap && f < cap && l < cap &&((s < cap && l == (f + s) % cap) ||(s == cap && l == f))) {
            //cout << "OK"<<endl;
            q += "OK";
        } else {
            //cout << "WRONG"<<endl;
            q+= "WRONG";
            if (c==1){
                //cout << "WRONG" << " ";
                //q+= "WRONG";
                int x;
                if (s==cap){
                    x=l;
                } else {
                    x = (l - s +cap)%cap;
                }
                //cout << x << endl;
                q += " " + to_string(x);
                
            } 
            if (c==2) {
                //cout << "WRONG" << " ";
                //q += "WRONG";
                int x;
                if (l == f) x = 0;
                else x = (l - f + cap) % cap;
                //cout << x << endl;
                q += " " + to_string(x);
            }
            if (c==3) {
                //cout << "WRONG" << " ";
                //q += "WRONG";
                int x;
                if(f<l) {
                    x=s+f+1;
                } else {
                    x=f-l+s;
                }
                //cout << x << endl;
                q += " " + to_string(x);
            }
            if (c==4) {
                //cout << "WRONG" << " ";
                //q += "WRONG";
                int x;
                if (s<cap){
                    x=(f+s)%cap;
                }
                else {
                    x=f;
                }
                //cout << x << endl;
                q += " " + to_string(x);

            }
        }
        result.push_back(q);
    }
    for (auto &x: result) {
        cout << x << endl;
    }
}
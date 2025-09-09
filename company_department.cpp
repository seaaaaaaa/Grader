#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    map<string, set<string>> current;
    map<string,string> dep;
    for (int i = 0; i < n; i++) {
        string name,dept;
        cin >> name >> dept;
        current[dept].insert(name);
        dep[name]=dept;
    }
    for (int i = 0 ; i<m;i++){
        int o;
        string a,b;
        cin >> o;
        if (o==1){
            cin >> a >> b;
            current[dep[a]].erase(a);
            current[b].insert(a);
            dep[a]=b;
        } else if(o==2){
            cin >> a >> b;
            for (const auto&x : current[a]) {
                current[b].insert(x);
                dep[x]=b;
            }
            current.erase(a);
        }
    }
    for (const auto& [dept, names] : current) {
        cout << dept << ": ";
        for (const auto& name : names) {
            cout << name << " ";
        }
        cout << "\n";
    }
}
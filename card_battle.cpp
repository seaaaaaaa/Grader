#include <iostream>
#include <vector> 
#include <algorithm>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    multiset<int> deck;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        deck.insert(x);
    }
    int round = 1;
    
    for (int i = 0; i < m; i++) {
        int o;
        cin >> o;
        for (int j=0; j<o;j++) {
            int op;
            cin >> op;
            auto it = deck.upper_bound(op);
            if (it == deck.end()) {
                cout << round;
                return 0;
            } else {
                deck.erase(it);
                if (deck.empty()) {
                    cout << round;
                    return 0;
                }
            }
       }
       round++;
    }
    cout << round;
    return 0;
}
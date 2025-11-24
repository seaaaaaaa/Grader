#include <iostream>
#include <vector>
using namespace std;
int relation(long long S, long long a, long long b) {
    long long ma = std::max(a,b);
    long long mi = std::min(a,b);
    if((ma-1)/S == mi) return 1;
    if(ma != mi){
        while(ma> mi){
            ma = (ma-1)/S;
        }
        if(ma == mi) return 2;
    }
    long long tmpa = a;
    long long tmpb = b;
    long long deptha = 0;
    long long depthb = 0;
    while (tmpa > 0){
        tmpa = (tmpa-1)/S;
        deptha++;
    }
    while (tmpb > 0){
        tmpb = (tmpb-1)/S;
        depthb++;
    }
    if(deptha == depthb) return 4;
    return 3;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long S,a,b;
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S,a,b) << " ";
    }
    cout << endl;
}
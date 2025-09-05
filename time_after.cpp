#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int h, m;
    cin >> h >> m;
    int a;
    cin >> a;
    m += a;
    while ( m>59 ) {
        m-= 60;
        h++;
    }
    while ( h>23 ) {
        h-= 24;
    }
    
    if (h < 10) {
        cout << "0" << h;
    } else {
        cout << h;   
    }
    cout << " ";
    if (m < 10) {
        cout << "0" << m;
    } else {
        cout << m;  
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>    
#include <utility>
using namespace std;
int eval_postfix(vector<pair<int,int> > v) {
    //WRITE YOUR CODE HERE
    //DON"T FORGET TO RETURN THE RESULT
  stack<int> s;
  for (auto &p:v) {
    if (p.first == 0) {
        if (p.second == 0 ) {
            int x1,x2;
            x1=s.top();
            s.pop();
            x2=s.top();
            s.pop();
            int result = x2+x1;
            s.push(result);
            //cout << result << endl;
        }
        if (p.second == 1 ) {
            int x1,x2;
            x1=s.top();
            s.pop();
            x2=s.top();
            s.pop();
            int result = x2-x1;
            s.push(result);
            //cout << result << endl;
        }
        if (p.second == 2 ) {
            int x1,x2;
            x1=s.top();
            s.pop();
            x2=s.top();
            s.pop();
            int result = x2*x1;
            s.push(result);
            //cout << result << endl; 
        }
        if (p.second == 3 ) {
            int x1,x2;
            x1=s.top();
            s.pop();
            x2=s.top();
            s.pop();
            int result = x2/x1;
            s.push(result);
            //cout << result << endl;
        }
    } else if(p.first == 1){
      s.push(p.second);
    }
   
  }
  return s.top();
} 
int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i].first >> v[i].second;
    }   
    int answer = eval_postfix(v);
    cout << answer;
}
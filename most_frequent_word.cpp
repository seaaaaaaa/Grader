#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    map<string, int> word_count;
    for (int i =0 ; i <n; i++) {
        string word;
        cin >> word;
        word_count[word]++;  
    }
    vector<pair<string, int>> word_freq(word_count.begin(), word_count.end());
    sort(word_freq.begin(), word_freq.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second != b.second)
            return a.second > b.second; // Sort by frequency descending
        return a.first > b.first; // If frequencies are equal, sort lexicographically
    });
    cout << word_freq[0].first << " " << word_freq[0].second << endl;;
    return 0;
}
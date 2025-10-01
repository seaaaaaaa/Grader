#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    set<pair<int, int>> intervals;
    long long dc = 0;
    int N,Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int lt,rt;
        cin >> lt >> rt;
        
        auto it = intervals.upper_bound({lt, 0});

            // The interval *before* this one might also overlap, so we safely step back if possible.
            // This is the correct way to avoid decrementing s.begin().
            if (it != intervals.begin()) {
                it--;
            }

            // Loop through all intervals that could possibly merge.
            // A merge is possible if the candidate interval starts before our current one ends (plus a gap of 1).
            while (it != intervals.end() && it->first <= rt + 1) {
                
                // If the candidate interval ends too early, it can't merge. Skip it.
                if (it->second < lt - 1) {
                    it++;
                }else{

                    // An overlap was found! Merge by expanding the [start, end] range.
                    lt = min(lt, it->first);
                    rt = max(rt, it->second);

                    dc -= (long long)(it->second - it->first + 1);
                // Erase the old interval. The iterator returned by erase points to the next element,
                // allowing our loop to continue safely without invalidating 'it'.
                    it = intervals.erase(it);
                }    
            }
        intervals.insert({lt, rt});
        dc += (long long)(rt - lt + 1);
        cout << N - dc << "\n";
    }
    
}


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits> // Required for INT_MAX

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int start, end;
            cin >> start >> end;

            // Find a safe starting point for our search loop.
            // We look for the first interval that starts *after* our new interval's start time.
            auto it = s.upper_bound({start, INT_MAX});

            // The interval *before* this one might also overlap, so we safely step back if possible.
            // This is the correct way to avoid decrementing s.begin().
            if (it != s.begin()) {
                it--;
            }

            // Loop through all intervals that could possibly merge.
            // A merge is possible if the candidate interval starts before our current one ends (plus a gap of 1).
            while (it != s.end() && it->first <= end + 1) {
                
                // If the candidate interval ends too early, it can't merge. Skip it.
                if (it->second < start - 1) {
                    it++;
                    continue;
                }

                // An overlap was found! Merge by expanding the [start, end] range.
                start = min(start, it->first);
                end = max(end, it->second);

                // Erase the old interval. The iterator returned by erase points to the next element,
                // allowing our loop to continue safely without invalidating 'it'.
                it = s.erase(it);
            }

            // After the loop has merged all possible intervals, insert the final, combined result.
            s.insert({start, end});

        } else if (o == 2) {
            // This query operation remains perfectly efficient.
            cout << s.size() << "\n";
        }
    }
    return 0;
}
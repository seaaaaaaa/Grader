#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int goat_amt, days;
vector<int> goat_pos;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input all goat positions and sort them in ascending order
    cin >> goat_amt;
    goat_pos.resize(goat_amt);
    for(int i = 0; i < goat_amt; i++)
    {
        cin >> goat_pos[i];
    }
    sort(goat_pos.begin(), goat_pos.end());

    // Output the shortest distance between goat and wolf each day
    cin >> days;
    while(days--)
    {
        // Input wolf position
        int wolf_pos;
        cin >> wolf_pos;

        // Find the lower_bound on the goat positions array.
        // This gives us the first goat position that is not less than the wolf position.
        vector<int>::iterator it = lower_bound(goat_pos.begin(), goat_pos.end(), wolf_pos);
        
        // If the wolf is beyond the last goat
        if (it == goat_pos.end())
        {
            cout << abs(wolf_pos - goat_pos.back()) << "\n";
        }

        // If the wolf is before the first goat
        else if (it == goat_pos.begin())
        {
            cout << abs(wolf_pos - goat_pos.front()) << "\n";
        }

        // If the wolf is between two goats
        else
        {
            cout << min(abs(wolf_pos - *it), abs(wolf_pos - *(it - 1))) << "\n";
        }
    }
    return 0;
}
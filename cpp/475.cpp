#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int res = 0;
        int j = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++)
        {
            while (j < heaters.size() - 1 && heaters[j] + heaters[j + 1] < 2 * houses[i])
                j++;
            res = max(res, abs(heaters[j] - houses[i]));
        }
        return res;
    }
};
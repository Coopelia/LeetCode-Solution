#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> cache;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (cache.empty())
                cache.push_back(nums[i]);
            else
            {
                auto pos = lower_bound(cache.begin(), cache.end(), nums[i]);
                res[i] = pos - cache.begin();
                cache.insert(pos, nums[i]);
            }
        }
        return res;
    }
};
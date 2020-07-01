#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int sum = 0, res = arr.size() + 1;
        vector<int> dp(arr.size(), arr.size() + 1);
        unordered_map<int, int> cnt;
        cnt[0] = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            cnt[sum] = i;
            if (i > 0)
                dp[i] = dp[i - 1];
            if (cnt.count(sum - target) != 0)
            {
                int last = cnt[sum - target];
                if (last >= 0 && dp[last] <= arr.size())
                    res = min(dp[last] + i - last, res);
                dp[i] = min(dp[i], i - last);
            }
        }
        return res > arr.size() ? -1 : res;
    }
};
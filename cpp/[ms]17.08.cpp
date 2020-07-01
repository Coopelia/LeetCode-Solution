#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bestSeqAtIndex(vector<int> &height, vector<int> &weight)
    {
        int n = height.size();
        if (n < 2)
            return n;
        vector<pair<int, int>> cnt;
        for (int i = 0; i < n; i++)
            cnt.push_back({height[i], weight[i]});
        sort(cnt.begin(), cnt.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        vector<int> dp;
        int pos;
        for (int i = 0; i < cnt.size(); i++)
        {
            pos = lower_bound(dp.begin(), dp.end(), cnt[i].second) - dp.begin();
            if (pos == dp.size())
                dp.push_back(cnt[i].second);
            else
                dp[pos] = cnt[i].second;
        }
        return dp.size();
    }
};
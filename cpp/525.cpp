#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int cnt = 0, re = 0;
        unordered_map<int, int> t;
        t.insert(pair<int, int>(0, -1));
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cnt--;
            else if (nums[i] == 1)
                cnt++;
            if (t.count(cnt))
                re = max(re, i - t[cnt]);
            else
                t[cnt] = i;
        }
        return re;
    }
};
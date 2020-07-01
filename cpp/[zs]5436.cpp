#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> re(nums.size(),0);
        re[0]=nums[0];
        for (int i = 1; i < nums.size(); i++)
            re[i]=nums[i]+re[i-1];
        return re;
    }
};
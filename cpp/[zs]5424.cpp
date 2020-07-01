#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int re=0;
        for (int i = 0; i < nums.size()-1; i++)
            for (int j = i+1; j < nums.size(); j++)
                re=max(re,(nums[i]-1)*(nums[j]-1));
        return re;
    }
};
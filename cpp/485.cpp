#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int m = 0, t = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                t++;
            else if (t != 0)
            {
                if (t > m)
                    m = t;
                t = 0;
            }
        }
        if (t > m)
            return t;
        return m;
    }
};
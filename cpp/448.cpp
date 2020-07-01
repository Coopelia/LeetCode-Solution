#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t(n, 1);
        for (int i = 0; i < n; i++)
            t[nums[i] - 1] = 0;
        nums.clear();
        for (int i = 0; i < t.size(); i++)
            if (t[i] != 0)
                nums.push_back(i + 1);

        return nums;
    }
};
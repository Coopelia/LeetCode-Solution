#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n=nums.size();
        int max=nums[0],temp=1;
        for (int i = 0; i < n; i++)
        {
            temp*=nums[i];
            if(temp>max)
                max=temp;
            if(nums[i]==0)
                temp=1;
        }
        temp=1;
        for (int i = n-1; i >= 0 ; i--)
        {
            temp*=nums[i];
            if(temp>max)
                max=temp;
            if(nums[i]==0)
                temp=1;
        }
        return max;
    }
};
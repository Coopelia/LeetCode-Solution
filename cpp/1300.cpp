#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        double res = 0.0;
        int sum = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            res = (double)(target - sum) / (n - i);
            if (res < arr[i])
                return res - floor(res) > 0.5 ? ceil(res) : floor(res);
            sum += arr[i];
        }
        return arr[n-1];
    }
};
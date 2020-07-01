#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &A)
    {
        int res = 0, left = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            res = max(res, left + A[i] - i);
            left = max(left, A[i] + i);
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        if (timePoints.size() < 2)
            return 0;
        vector<int> t;
        for (int i = 0; i < timePoints.size(); i++)
            t.push_back(atoi(timePoints[i].substr(0, 2).c_str()) * 60 + atoi(timePoints[i].substr(3, 2).c_str()));
        sort(t.begin(), t.end());
        int res = 10000;
        for (int i = 0; i < t.size() - 1; i++)
            res = min(res, t[i + 1] - t[i]);
        res = min(res, 1440 - t[t.size() - 1] + t[0]);
        return res;
    }
};
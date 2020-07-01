#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> cnt;
        for (int i = 0; i < arr.size(); i++)
            cnt[arr[i]]++;
        vector<pair<int, int>> vpr;
        map<int, int>::iterator itr;
        for (itr = cnt.begin(); itr != cnt.end(); itr++)
            vpr.push_back(make_pair(itr->first, itr->second));
        sort(vpr.begin(), vpr.end(), cmp);
        int res = cnt.size();
        int i = 0;
        while (k)
        {
            for (; i < vpr.size(); i++)
            {
                if (vpr[i].second == 0)
                    continue;
                if (vpr[i].second >= k)
                {
                    vpr[i].second -= k;
                    k = 0;
                    if (vpr[i].second == 0)
                        res--;
                    break;
                }
                else
                {
                    k -= vpr[i].second;
                    vpr[i].second = 0;
                    res--;
                }
            }
        }
        return res;
    }
};
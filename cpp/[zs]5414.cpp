#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        vector<int> res;
        for (auto &a : favoriteCompanies)
            sort(a.begin(), a.end());
        int n = favoriteCompanies.size();
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < n && flag; j++)
            {
                if (i == j)
                    continue;
                flag = !includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            }
            if (flag)
                res.push_back(i);
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int m_max=0;
        vector<bool> re;
        for (auto a:candies)
            if(a>m_max)
                m_max=a,m_max;
        for (auto a:candies)
        {
            if(a+extraCandies>=m_max)
                re.push_back(true);
            else 
                re.push_back(false);
        }
        return re;
    }
};
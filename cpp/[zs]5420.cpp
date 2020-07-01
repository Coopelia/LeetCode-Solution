#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> re=prices;
        for (int i = 0; i < re.size(); i++)
        {
            for (int j = i+1; j < re.size(); j++)
            {
                if(prices[j]<=prices[i])
                {
                    re[i]-=prices[j];
                    break;
                }
            }
        }
        return re;
    }
};
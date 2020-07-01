#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> P(m);
        for (int i = 0; i < P.size(); i++)
            P[i] = i + 1;
        int t;
        vector<int> re;
        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < P.size(); j++)
            {
                if (P[j] == queries[i])
                {
                    t = P[j];
                    for (int k = j; k > 0; k--)
                        P[k] = P[k - 1];
                    P[0] = t;
                    re.push_back(j);
                    goto fg;
                }
            }
        fg:
            continue;
        }
        return re;
    }
};
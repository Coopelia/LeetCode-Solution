#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        stack<int> s;
        vector<int> re(T.size(), 0);
        if (T.size() < 2)
            return re;
        for (int i = 0; i < T.size(); i++)
        {
            while (!s.empty() && T[i] > T[s.top()])
            {
                re[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return re;
    }
};
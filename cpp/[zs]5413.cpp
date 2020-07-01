#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string arrangeWords(string text)
    {
        int index = 0, t_len = text.size();
        text[0] += 32;
        vector<pair<string, int>> res;
        for (int i = 0; i <= t_len; i++)
        {
            if (i == t_len || text[i] == ' ')
            {
                res.push_back(make_pair(text.substr(index, i - index), res.size()));
                index = i + 1;
            }
        }
        sort(
            res.begin(),
            res.end(),
            [](const auto &a, const auto &b) 
            {
                return a.first.size() == b.first.size() ? a.second < b.second : a.first.size() < b.first.size();
            }
            );
        string ans;
        ans.reserve(t_len + 1);
        for (int i = 0; i < res.size(); i++)
        {
            ans += res[i].first + " ";
        }
        ans[0] -= 32;
        ans.resize(t_len);
        return ans;
    }
};
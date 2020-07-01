#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string res;
        int j = 0;
        char c;
        bool flag = true;
        while (flag)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                if (j >= strs[i].size())
                {
                    flag = false;
                    break;
                }
                if (i == 0)
                    c = strs[i][j];
                else
                {
                    if (strs[i][j] != c)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                res.push_back(c);
            j++;
        }
        return res;
    }
};
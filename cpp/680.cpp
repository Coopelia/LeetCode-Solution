#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool flag;
    string ms;
    bool isHuiWen(int i, int j)
    {
        if (i == j)
            return true;
        if (ms[i] == ms[j])
        {
            if (i + 1 == j)
                return true;
            return isHuiWen(i + 1, j - 1);
        }
        else if (flag)
        {
            flag = false;
            if (isHuiWen(i + 1, j))
                return true;
            else
                return isHuiWen(i, j - 1);
        }
        else 
            return false;
    }
    bool validPalindrome(string s)
    {
        ms = s;
        flag = true;
        return isHuiWen(0, s.length() - 1);
    }
};
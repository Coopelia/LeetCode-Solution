#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string ss;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                ss.push_back(s[i]);
            else if (s[i] >= 'A' && s[i] <= 'Z')
                ss.push_back(tolower(s[i]));
        }
        if (ss.size() <= 1)
            return true;
        int i = 0, j = ss.size() - 1;
        while (i < j)
        {
            if (ss[i++] != ss[j--])
                return false;
        }
        return true;
    }
};
#include <iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0)
            return false;
        vector<int> l;
        while (x)
        {
            l.push_back(x%10);
            x/=10;
        }
        for (int i = 0; i < l.size()/2; i++)
        {
            if(l[i]!=l[l.size()-i-1])
                return false;
        }
        return true;
    }
};
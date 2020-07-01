#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isSs(int n)
    {
        if (n == 0 || n == 1)
            return false;
        for (int i = 2; i <= sqrt(abs(n)); i++)
            if (n % i == 0)
                return false;
        return true;
    }

    bool isHw(int n)
    {
        string s;
        while (n)
        {
            s.push_back(n % 10 + '0');
            n /= 10;
        }
        for (int i = 0; i < s.size() / 2; i++)
            if (s[i] != s[s.size() - i - 1])
                return false;
        return true;
    }

    int primePalindrome(int N)
    {
        while (true)
        {
            if (isHw(N))
                if(isSs(N))
                    return N;
            N++;
        }
        return 0;
    }
};
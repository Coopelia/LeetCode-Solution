#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool isZhen = ((divisor > 0 && dividend > 0) || (dividend < 0 && divisor < 0));
        unsigned int end = abs(dividend);
        unsigned int sor = abs(divisor);
        if (end < sor)
            return 0;
        if (sor == 1)
            return isZhen ? end : -end;
        int re = 0;
        for (int i = 31; i >= 0; i--)
        {
            if ((end >> i) >= sor)
            {
                re += (1 << i);
                end -= (sor << i);
            }
        }
        return isZhen ? re : -re;
    }
};
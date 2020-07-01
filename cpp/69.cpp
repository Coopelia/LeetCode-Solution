#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int left = 1, right = x, mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (mid * mid == x)
                return mid;
            if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};
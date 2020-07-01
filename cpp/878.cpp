#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B)
    {
        int lcm = A * B / gcd(A, B);
        long left = 2, right = min(A, B) * (long)N;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            int n = mid / A + mid / B - mid / lcm;
            if (n >= N)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left % (int)(1e9 + 7);
    }
};
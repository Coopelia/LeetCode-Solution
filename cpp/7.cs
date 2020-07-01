using System;

public class Solution {
    public int Reverse (int x) {
        Int64 res = 0;
        while (x != 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if (res < Int32.MinValue || res > Int32.MaxValue)
            return 0;
        return Convert.ToInt32 (res);
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool solve(int N, int i)
    {
        if (N <= 1)
            return false;
        if (i == 0)
        {
            for (int x = 1; x < N && N % x == 0; x++)
                if (!solve(N - x, 1))
                    return true;
        }
        else
        {
            for (int x = 1; x < N && N % x == 0; x++)
                if (!solve(N - x, 0))
                    return true;
        }
        return false;
    }

    bool divisorGame(int N)
    {
        return solve(N, 0);
    }
};
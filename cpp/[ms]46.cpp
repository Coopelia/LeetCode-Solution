#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int num)
    {
        if(num<10)
            return 1;
        int t=num%100;
        if(t<26&&t>9)
            return solve(num/10)+solve(num/100);
        else 
            return solve(num/10);
    }

    int translateNum(int num)
    {
        if(num==0)
            return 1;
        return solve(num);
    }
};
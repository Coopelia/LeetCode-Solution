#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        char a[2];
        int fg = 0;
        int arr[200];
        bool flag = false;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < A.size(); i++)
        {
            if (arr[A[i] - '0'] == 1)
                flag = true;
            else
                arr[A[i] - '0'] = 1;
            if (A[i] != B[i])
            {
                if (fg == 0)
                {
                    fg = 1;
                    a[0] = A[i];
                    a[1] = B[i];
                }
                else if (fg == 1)
                {
                    if (A[i] == a[1] && B[i] == a[0])
                        fg = 2;
                }
                else
                    return false;
            }
        }
        if (fg == 2 || (fg == 0 && flag))
            return true;
        return false;
    }
};
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] == '0' && s[i + 1] == '0')
                return 0;
        string ss;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i + 1] == '0')
            {
                if (s[i] <= '2')
                    i++;
                else
                    return 0;
            }
            else
                ss.push_back(s[i]);
        }
        if (s[s.size() - 1] != '0')
            ss.push_back(s[s.size() - 1]);
        if (ss.size() <= 1)
            return 1;
        int a, b;
        if (((ss[0] - '0') * 10 + ss[1] - '0' > 26))
        {
            a = 1;
            b = 1;
        }
        else
        {
            a = 1;
            b = 2;
        }
        int temp;
        for (int i = 2; i < ss.size(); i++)
        {
            if ((ss[i - 1] - '0') * 10 + ss[i] - '0' > 26)
                temp = b;
            else
                temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main()
{
    Solution so;
    string s;
    cin >> s;
    cout << so.numDecodings(s);
    system("pause");
    return 0;
}
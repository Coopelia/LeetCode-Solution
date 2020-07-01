#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        vector<int> list;
        int f = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (list.size() == 0)
            {
                if (str[i] == ' ' && f == 0)
                    continue;
                if (f == 0 && str[i] == '-')
                    f = -1;
                else if (f == 0 && str[i] == '+')
                    f = 1;
                else if (str[i] < '0' || str[i] > '9')
                    return 0;
                else
                    list.push_back(str[i] - '0');
            }
            else
            {
                if (str[i] < '0' || str[i] > '9')
                    break;
                list.push_back(str[i] - '0');
            }
        }
        double res = 0;
        if (f == 0)
            f = 1;
        for (int i = 0; i < list.size(); i++)
        {
            res += f * list[i] * pow(10, list.size() - i - 1);
            if (res >= INT_MAX)
            {
                res = INT_MAX;
                break;
            }
            if (res <= INT_MIN)
            {
                res = INT_MIN;
                break;
            }
        }
        return int(res);
    }
};

int main()
{
    Solution so;
    string s;
    cin >> s;
    cout << so.myAtoi(s);
    system("pause");
    return 0;
}
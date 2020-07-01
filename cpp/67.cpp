#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    ::std::string addBinary(::std::string a, ::std::string b)
    {
        bool fg = false;
        int i = 0;
        if (a.size() < b.size())
            swap(a, b);
        int la = a.size() - 1;
        int lb = b.size() - 1;
        while (true)
        {
            if (i > lb && !fg)
                break;
            if (i > la)
            {
                if (fg)
                    a.insert(a.begin(), '1');
                break;
            }
            if (fg)
            {
                if (a[la - i] == '0')
                {
                    a[la - i] = '1';
                    fg = false;
                }
                else
                {
                    a[la - i] = '0';
                    fg = true;
                }
            }
            if (i <= lb)
            {
                if (a[la - i] + b[lb - i] - 2 * '0' == 2)
                {
                    a[la - i] = '0';
                    fg = true;
                }
                else
                    a[la - i] = a[la - i] + b[lb - i] - '0';
            }
            i++;
        }
        return a;
    }
};
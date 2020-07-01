#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int left = 0, right = 0, start = 0, minlen = INT_MAX;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (int i = 0; i < t.length(); i++)
            need[t[i]]++;
        int match = 0;
        while (right < s.length())
        {
            char c1 = s[right];
            if (need.count(c1))
            {
                window[c1]++;
                if (window[c1] == need[c1])
                    match++;
            }
            right++;
            while (match == need.size())
            {
                if (right - left < minlen)
                {
                    minlen = right - left;
                    start = left;
                }
                char c2 = s[left];
                if (need.count(c2))
                {
                    window[c2]--;
                    if (window[c2] < need[c2])
                        match--;
                }
                left++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int ans = 0, status = 0, n = s.size();
        vector<int> pos(32, -1);
        pos[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                status ^= 1 << 0;
            }
            else if (s[i] == 'e')
            {
                status ^= 1 << 1;
            }
            else if (s[i] == 'i')
            {
                status ^= 1 << 2;
            }
            else if (s[i] == 'o')
            {
                status ^= 1 << 3;
            }
            else if (s[i] == 'u')
            {
                status ^= 1 << 4;
            }
            if (pos[status] != -1)
            {
                ans = max(ans, i + 1 - pos[status]);
            }
            else
            {
                pos[status] = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution so;
    string s;
    cin >> s;
    cout << so.findTheLongestSubstring(s);
    system("pause");
    return 0;
}
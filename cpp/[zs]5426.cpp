#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int ans=0;
        set<int> m;
        m.insert(0);
        for (auto a : connections)
        {
            if(m.find(a[1])==m.end())
            {
                ans++;
                m.insert(a[1]);
            }
            else 
                m.insert(a[0]);
        }
        return ans;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int roots[26];
    int ranks[26];
    Solution()
    {
        for (int i = 0; i < 26; i++) 
        {
            roots[i]=-1;
            ranks[i]=0;
        }    
    }

    int findRoot(int x)
    {
        int x_root=x;
        while (roots[x_root]!=-1)
            x_root=roots[x_root];
        return x_root;
    }

    void Union(int x,int y)
    {
        int x_root=findRoot(x);
        int y_root=findRoot(y);
        if(x_root==y_root)
            return;
        if(ranks[x_root]<ranks[y_root])
        {
            roots[x_root]=y_root;
            ranks[y_root]++;
        }
        else 
        {
            roots[y_root]=x_root;
            ranks[x_root]++;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        for (auto s:equations)
        {
            if(s[1]=='=')
                Union(s[0]-97,s[3]-97);
        }
        for (auto s:equations)
        {
            if(s[1]=='!'&&findRoot(s[0]-97)==findRoot(s[3]-97))
                return false;
        }
        return true;
    }
};
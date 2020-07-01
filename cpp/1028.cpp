#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *solve(string &s, int d, int &next)
    {
        if (s.empty())
            return NULL;
        int num = 0, i;
        for (i = 0; i < s.size() && s[i] != '-'; i++)
        {
            num *= 10;
            num += s[i] - '0';
        }
        TreeNode *node = new TreeNode(num);
        if (i == s.size())
        {
            s.clear();
            return node;
        }
        s = s.substr(i, s.size() - i);
        i = 0;
        while (s[i++] == '-');
        i--;
        s = s.substr(i, s.size() - i);
        if (i == d + 1)
            node->left = solve(s, i, i);
        if (i == d + 1)
            node->right = solve(s, i, i);
        next = i;
        return node;
    }

    TreeNode *recoverFromPreorder(string S)
    {
        int n;
        return solve(S, 0, n);
    }
};
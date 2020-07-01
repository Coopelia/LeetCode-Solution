#include <vector>
#include <iostream>
#include <algorithm>
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
    int res;
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));
        res = max(res, root->val + left + right);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        res = root->val;
        solve(root);
        return res;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
    bool solve(TreeNode* p,TreeNode* q)
    {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        if(p->val==q->val)
            return (solve(p->left,q->right)&&solve(p->right,q->left));
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return solve(root,root);
    }
};
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "n";
        string s = to_string(root->val);
        s.push_back(';');
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        return func(data);
    }

    TreeNode *func(string &data)
    {
        if (data[0] == 'n')
        {
            data.erase(data.begin());
            return NULL;
        }
        int a = 0, fg = 1;
        std::string::iterator itr;
        for (itr = data.begin(); (*itr) != ';';)
        {
            if ((*itr) == '-')
                fg = -1;
            else
            {
                a *= 10;
                a += (*itr) - '0';
            }
            itr = data.erase(itr);
        }
        data.erase(itr);
        TreeNode *node = new TreeNode(a * fg);
        if (data.empty())
            return node;
        node->left = func(data);
        if (data.empty())
            return node;
        node->right = func(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
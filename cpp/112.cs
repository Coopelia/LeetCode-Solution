using System;
using System.Collections;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution
{
    public bool HasPathSum(TreeNode root, int sum)
    {
        if (root == null)
            return false;
        sum -= root.val;
        if (root.left == null && root.right == null)
            return sum == 0;
        return HasPathSum(root.left, sum) || HasPathSum(root.right, sum);
    }
}
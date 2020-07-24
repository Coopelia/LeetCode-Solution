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
    public int[] arr;
    public TreeNode solve(int i, int j)
    {
        if (i > j)
            return null;
        int mid = (i + j) >> 1;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = solve(i, mid - 1);
        root.right = solve(mid + 1, j);
        return root;
    }
    public TreeNode SortedArrayToBST(int[] nums)
    {
        this.arr = nums;
        return solve(0, arr.Length - 1);
    }
}
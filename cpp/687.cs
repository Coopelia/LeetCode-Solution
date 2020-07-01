using System;
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode (int x) { val = x; }
}
public class Solution {
    public int res;
    public int solve (TreeNode root, int val) {
        if (root == null)
            return 0;
        int left = solve (root.left, root.val);
        int right = solve (root.right, root.val);
        res = Math.Max (res, left + right);
        if (root.val == val)
            return Math.Max (left, right) + 1;
        return 0;
    }
    public int LongestUnivaluePath (TreeNode root) {
        if (root == null)
            return 0;
        this.res = 0;
        solve (root, root.val);
        return res;
    }
}
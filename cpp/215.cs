using System;
using System.Collections;

public class Solution
{
    public int FindKthLargest(int[] nums, int k)
    {
        Array.Sort(nums, new Comparison<int>((a, b) => b.CompareTo(a)));
        return nums[k - 1];
    }
}
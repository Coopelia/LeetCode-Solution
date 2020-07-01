using System;
public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        Array.Sort(nums);
        int res = 0, d = Int32.MaxValue;
        int low, high, sum, td;
        for (int i = 0; i < nums.Length - 2; i++)
        {
            low = i + 1;
            high = nums.Length - 1;
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                td = Math.Abs(sum - target);
                if (td < d)
                {
                    d = td;
                    res = sum;
                }
                if (sum == target)
                    return sum;
                if (sum > target)
                    high--;
                else
                    low++;
            }
        }

        return res;
    }
}
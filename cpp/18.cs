using System;
using System.Collections;

public class Solution
{
    public IList<IList<int>> FourSum(int[] nums, int target)
    {
        IList<IList<int>> res = new List<IList<int>>();
        if (nums.Length < 4)
            return res;
        Array.Sort(nums);
        int i, j, low, hight;
        for (i = 0; i < nums.Length - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (j = i + 1; j < nums.Length - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                low = j + 1;
                hight = nums.Length - 1;
                while (low < hight)
                {
                    if (nums[i] + nums[j] + nums[low] + nums[hight] == target)
                    {
                        IList<int> p = new List<int>();
                        p.Add(nums[i]);
                        p.Add(nums[j]);
                        p.Add(nums[low]);
                        p.Add(nums[hight]);
                        res.Add(p);
                        while (low < hight && nums[low] == nums[low + 1]) low++;
                        while (low < hight && nums[hight] == nums[hight - 1]) hight--;
                        low++;
                        hight--;
                    }
                    else if (nums[i] + nums[j] + nums[low] + nums[hight] < target)
                        low++;
                    else
                        hight--;
                }
            }
        }
        return res;
    }
}
using System;

public class Solution
{
    public int MinSubArrayLen(int s, int[] nums)
    {
        int size, t;
        for (size = 1; size <= nums.Length; size++)
        {
            t = 0;
            for (int i = 0; i < size; i++)
                t += nums[i];
            if (t >= s)
                return size;
            for (int i = 0; i < nums.Length - size; i++)
            {
                t += nums[i + size] - nums[i];
                if (t >= s)
                    return size;
            }
        }
        return 0;
    }
}
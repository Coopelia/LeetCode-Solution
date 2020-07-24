using System;
using System.Collections;
using System.Collections.Generic;

public class Solution
{
    public int[] DivingBoard(int shorter, int longer, int k)
    {
        List<int> t = new List<int>();
        if (k == 0)
            return t.ToArray();
        if (shorter == longer)
        {
            t.Add(k * shorter);
            return t.ToArray();
        }
        for (int i = 0; i <= k; i++)
            t.Add(i * longer + (k - i) * shorter);
        for (int i = 0; i < t.Count - 1;)
        {
            if (t[i] == t[i + 1])
                t.Remove(t[i + 1]);
            else
                i++;
        }
        return t.ToArray();
    }
}
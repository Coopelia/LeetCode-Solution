using System;
using System.Collections;

public class Solution
{
    public int FindLength(int[] A, int[] B)
    {
        int res = 0, t = 0;
        for (int i = 1 - A.Length; i < A.Length - t; i++)
        {
            t = 0;
            for (int j = i < 0 ? -i : 0; j < B.Length && i + j < A.Length; j++)
            {
                if (A[i + j] == B[j])
                    t++;
                else if (t > 0)
                {
                    res = Math.Max(res, t);
                    t = 0;
                }
            }
            res = Math.Max(res, t);
            if (res == B.Length)
                break;
        }
        return res;
    }
}
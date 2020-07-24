using System;
using System.Collections;

public class Solution
{
    public int KthSmallest(int[][] matrix, int k)
    {
        int n = matrix.Length;
        int[] arr = new int[n * n];
        int t = 0, i, j;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                arr[t++] = matrix[i][j];
        Array.Sort(arr);
        return arr[k - 1];
    }
}
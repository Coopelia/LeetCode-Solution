using System;
using System.Collections;

public class Solution
{
    public int[][] stepArr;
    public int[][] memArr;
    public int solve(int i, int j)
    {
        if (i >= stepArr.Length || j >= stepArr[0].Length || stepArr[i][j] == 1)
            return 0;
        if (i == stepArr.Length - 1 && j == stepArr[0].Length - 1)
            return 1;
        if (memArr[i][j] == 0)
            memArr[i][j] = solve(i + 1, j) + solve(i, j + 1);
        return memArr[i][j];
    }
    public int UniquePathsWithObstacles(int[][] obstacleGrid)
    {
        stepArr = obstacleGrid;
        memArr = new int[obstacleGrid.Length][];
        for (int i = 0; i < obstacleGrid.Length; i++)
            memArr[i] = new int[obstacleGrid[0].Length];
        return solve(0, 0);
    }
}
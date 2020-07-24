using System;
using System.Collections;

public class Solution
{
    public bool IsMatch(string s, string p)
    {
        bool[][] dp = new bool[p.Length + 1][];
        for (int i = 0; i < p.Length + 1; i++)
            dp[i] = new bool[s.Length + 1];
        dp[0][0] = true;
        for (int i = 1; i <= s.Length; i++)
            dp[0][i] = false;
        for (int i = 1; i <= p.Length; i++)
        {
            if (p[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0];
                for (int j = 1; j <= s.Length; j++)
                    dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
            }
            else if (p[i - 1] == '?')
            {
                dp[i][0] = false;
                for (int j = 1; j <= s.Length; j++)
                    dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][0] = false;
                for (int j = 1; j <= s.Length; j++)
                    dp[i][j] = s[j - 1] == p[i - 1] && dp[i - 1][j - 1];
            }
        }
        return dp[p.Length][s.Length];
    }
}
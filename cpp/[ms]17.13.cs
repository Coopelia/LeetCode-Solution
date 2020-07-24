using System;
using System.Collections;

public class Solution
{
    public int Respace(string[] dictionary, string sentence)
    {
        int[] dp = new int[sentence.Length + 1];
        dp[0] = 0;
        for (int i = 0; i < sentence.Length; i++)
        {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j < dictionary.Length; j++)
                if (dictionary[j].Length <= i + 1 && dictionary[j] == sentence.Substring(i + 1 - dictionary[j].Length, dictionary[j].Length))
                    dp[i + 1] = Math.Min(dp[i + 1], dp[i + 1 - dictionary[j].Length]);
        }
        return dp[sentence.Length];
    }
}
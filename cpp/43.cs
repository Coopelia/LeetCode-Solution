using System;
using System.Collections;
using System.Text;

public class Solution
{
    public string Multiply(string num1, string num2)
    {
        if (num1.Length == 0 || num2.Length == 0)
            return "";
        int n1 = num1.Length, n2 = num2.Length;
        int[] bitarr = new int[n1 + n2];
        int t;
        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                t = (num1[i] - '0') * (num2[j] - '0');
                t += bitarr[i + j + 1];
                bitarr[i + j] += t / 10;
                bitarr[i + j + 1] = t % 10;
            }
        }
        StringBuilder res = new StringBuilder();
        bool fg = true;
        for (int i = 0; i < bitarr.Length; i++)
        {
            if (bitarr[i] != 0 && fg == true)
                fg = false;
            if (fg == true)
                continue;
            else
                res.Append(bitarr[i]);
        }
        if (res.Length == 0)
            return "0";
        return res.ToString();
    }
}
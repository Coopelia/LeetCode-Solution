using System;
using System.Collections;

public class Solution
{
    public int LongestValidParentheses(string s)
    {
        Stack<int> stack = new Stack<int>();
        ArrayList arr = new ArrayList();
        for (int i = 0; i < s.Length; i++)
        {
            if (stack.Count == 0)
                stack.Push(i);
            else
            {
                switch (s[i])
                {
                    case '(':
                        stack.Push(i);
                        break;
                    case ')':
                        if (s[stack.Peek()] == '(')
                        {
                            arr.Add(stack.Pop());
                            arr.Add(i);
                        }
                        else
                            stack.Push(i);
                        break;
                    default:
                        break;
                }
            }
        }
        int t = 0, res = 0;
        arr.Sort();
        for (int i = 0; i < arr.Count; i++)
        {
            if (i == 0)
                t = 1;
            else if (Convert.ToInt32(arr[i - 1]) + 1 == Convert.ToInt32(arr[i]))
                t++;
            else
            {
                res = Math.Max(res, t);
                t = 1;
            }
        }
        return Math.Max(res, t);
    }
}
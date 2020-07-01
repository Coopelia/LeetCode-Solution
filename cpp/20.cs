using System.Collections;

public class Solution {
    public bool isMatch (char a, char b) {
        if (a == '(' && b == ')')
            return true;
        if (a == '[' && b == ']')
            return true;
        if (a == '{' && b == '}')
            return true;
        return false;
    }
    public bool IsValid (string s) {
        Stack<char> stack=new Stack<char>();
        for (int i = 0; i < s.Length; i++) {
            if (stack.Count == 0 || !isMatch (stack.Peek (), s[i]))
                stack.Push (s[i]);
            else
                stack.Pop ();
        }
        if (stack.Count == 0)
            return true;
        else
            return false;
    }
}
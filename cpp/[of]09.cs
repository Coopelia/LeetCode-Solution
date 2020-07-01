using System;
using System.Collections;

public class CQueue
{
    public Stack<int> stack_0, stack_1;

    public CQueue()
    {
        stack_0 = new Stack<int>();
        stack_1 = new Stack<int>();
    }

    public void AppendTail(int value)
    {
        while (stack_1.Count != 0)
            stack_0.Push(stack_1.Pop());
        stack_0.Push(value);
        while (stack_0.Count != 0)
            stack_1.Push(stack_0.Pop());
    }

    public int DeleteHead()
    {
        if (stack_1.Count == 0)
            return -1;
        return stack_1.Pop();
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.AppendTail(value);
 * int param_2 = obj.DeleteHead();
 */
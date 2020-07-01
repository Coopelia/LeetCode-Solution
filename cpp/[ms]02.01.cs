using System;
using System.Collections;

public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int x) { val = x; }
}

public class Solution
{
    public ListNode RemoveDuplicateNodes(ListNode head)
    {
        if (head == null)
            return null;
        int[] arr = new int[20001];
        ListNode p = head;
        arr[p.val] = 1;
        while (p.next != null)
        {
            if (arr[p.next.val] != 1)
            {
                p = p.next;
                arr[p.val] = 1;
            }
            else
                p.next = p.next.next;
        }
        return head;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(head==NULL)
            return NULL;
        vector<Node*> list;
        Node* p=head;
        Node* m_head=new Node(p->val);
        while (p!=NULL)
        {
            list.push_back(p);
            
        }
        
    }
};
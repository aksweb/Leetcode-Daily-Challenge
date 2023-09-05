/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *curr = head;
        Node *nHead = new Node(curr->val);
        // copy of the new head
        Node *c2 = nHead;

        if (curr->next == NULL)
        {
            if (curr->random != NULL)
                nHead->random = nHead;
            return nHead;
        }
        curr = curr->next;

        int n = 1;
        while (curr != NULL)
        {
            int tval = curr->val;
            // creating node and linking next
            Node *tnode = new Node(tval);
            c2->next = tnode;
            c2 = c2->next;
            curr = curr->next;
            n++;
        }
        // storing random
        curr = head;
        c2 = nHead;
        while (curr != NULL)
        {
            Node *tnode = curr->random;
            Node *tn2 = nHead;
            int m = 0;
            while (tnode != NULL)
            {
                m++;
                tnode = tnode->next;
            }
            int p = n - m;
            for (int i = 0; i < p; i++)
            {
                tn2 = tn2->next;
            }
            c2->random = tn2;
            c2 = c2->next;
            curr = curr->next;
        }

        return nHead;
        ;
    }
};
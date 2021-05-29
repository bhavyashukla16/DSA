//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1#
//O(N)
Node* rotate(Node* head, int k)
    {
        // Your code here
        Node *temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        Node *curr = head;
        while(k--)
        {
            temp->next = curr;
            temp = curr;
            curr = curr->next;
        }
        
        temp->next = NULL;
        return curr;
    }
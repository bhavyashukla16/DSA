//https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1#

public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head==NULL) //when size of linked list is even
        return NULL;
        
        if(head->next==NULL) //when size is odd, last element remains as it is
        return head;
        
        Node *prev=head, *curr=head->next;
        Node *temp = head->next->next;
        curr->next = prev;
        
        prev->next = pairWiseSwap(temp);
        
        return curr;
    }
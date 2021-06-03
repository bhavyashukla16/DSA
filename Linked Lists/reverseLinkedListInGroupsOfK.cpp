//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head)
            return NULL;
            
        node *prev=NULL, *curr=head;
        int count=0;
        while(curr!=NULL && count<k)
        {
            node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        
        if(curr!=NULL)
            head->next = reverse(curr, k);
            
        return prev;
    }
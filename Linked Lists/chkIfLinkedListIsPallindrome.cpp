//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

// METHOD 1: Reverse the second half of the list n chk it its identical to the first half
Node* reverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        
        while(curr!=NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow_ptr=head, *fast_ptr=head;
        while(fast_ptr!=NULL && fast_ptr->next!=NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        Node *last = reverseList(slow_ptr);
        Node *first = head;
        while(first!=NULL && last!=NULL)
        {
            if(first->data != last->data)
                return false;
                
            first = first->next;
            last = last->next;
        }
        return true;
    }
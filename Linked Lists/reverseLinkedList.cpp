//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#

//METHOD 1: without recursion, making the current node point to the previous node
//TC: O(N) SC: O(1)
//Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node *prev = head;
        Node *curr = head->next;
        
        while(curr!=NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = NULL;
        
        return prev;
    }

//METHOD 2: Recursion

struct Node* reverseList(Node)
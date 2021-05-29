//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

//Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        set<Node*> s;
        while(head!=NULL)
        {
            if(s.find(head)!=s.end())
            {
                head->next = NULL;
                return;
            }
            
            s.insert(head);
            head = head->next;
        }
        return;
    }
//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

//METHOD 1:
// if any node points to an address of any previous node, it has a LOOP

bool detectLoop(Node* head)
    {
        // your code here
        set<Node*> s;
        
        while(head!=NULL)
        {
            if(s.find(head)!=s.end())
            return true;
            
            s.insert(head);
            head = head->next;
        }
        return false;
    }

//METHOD 2: Floyd's Cycle algorithm (FASTEST)
// if slow and fast pointer becomes equal at any point, it has a LOOP
/* with every iteration, the distance between the slow and fast pointers increases by 1 
suppose the initial distance is k then it becomes k+1 then k+2 n so on, 
they r bound to meet when distance becomes n i.e. the no. of nodes in the cycle*/
bool detectLoop(Node* head)
    {
        // your code here
        Node *slow_ptr = head;
        Node *fast_ptr = head;
        
        while(slow_ptr && fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slow_ptr == fast_ptr)
             return true;
        }
        
        return false;
    }
//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/#

//METHOD 1: set find

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    set<Node*> s;
    while(head1!=NULL)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    
    while(head2!=NULL)
    {
        if(s.find(head2)!=s.end())
        return head2->data;
        
        head2 = head2->next;
    }
    
    return -1;
}

//METHOD 2: Faster

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
     int c1=0, c2=0; //length of list1 n list2
    Node* temp = head1;
    while(temp!=NULL)
    {
        c1++;
        temp = temp->next;
    }
    
    temp=head2;
    while(temp!=NULL)
    {
        c2++;
        temp = temp->next;
    }
    
    int d = abs(c1-c2); //diff bet their lengths
    int c=0;
    if(c1>=c2) //if first list is longer travel d nodes so that head points to (d+1)th node
    {
        while(head1!=NULL)
        {
            c++;
            if(c == d+1)
                break;
                
            head1 = head1->next;
        }
    }
    
    if(c1<c2) //if 2nd list is longer
    {
        while(head2!=NULL)
        {
            c++;
            if(c == d+1)
                break;
                
            head2 = head2->next;
        }
    }
    //now both lists r of equal lengths travel till u find the first common node
    while(head1!=NULL && head2!=NULL)
    {
        if(head1 == head2)
            return head1->data;
            
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}



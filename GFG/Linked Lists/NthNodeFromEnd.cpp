//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//METHOD 1: first calculate length of linked list and then return (Length-N+1)th Node from beginning
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* temp = head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp = temp->next;
    }
    
    temp = head;
    int c=1;
    while(temp!=NULL)
    {
        if(c == length-n+1)
            return temp->data;
        c++;
        temp = temp->next;
    }
    
    return -1;
}

//METHOD 2: Reverse the list n return Nth node from beginning
struct Node* reverseList(struct Node *head) {
    
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

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* new_head = reverseList(head);
    int c=1;
    while(new_head!=NULL)
    {
        if(c==n)
            return new_head->data;
        c++;
        new_head = new_head->next;
    }
    
    return -1;
}
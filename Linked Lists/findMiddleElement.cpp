//https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

//METHOD 1: Traverse to find its length, then traverse again upto length/2
//TC: O(N) SC: O(1)
int getMiddle(Node *head)
{
   // Your code here
   Node *ptr = head;
   int length = 0;
   
   while(ptr!=NULL)
   {
       length++;
       ptr = ptr->next;
   }
   //cout<<length<<" ";
   ptr = head;
   int l = -1;
   while(ptr!=NULL)
   {
       l++;
       if(l == length/2)
       return ptr->data;
       ptr = ptr->next;
   }
}


//METHOD 2: Traverse by increasing slow ptr by 1 and fast ptr by 2, by the time fast ptr reaches end, slow ptr will be at middle
//TC: O(N) SC: O(1)
int getMiddle(Node *head)
{
   // Your code here
   Node *slow_pointer = head;
   Node *fast_pointer = head;
   
   if(head!=NULL)
   {
       while(fast_pointer!=NULL && fast_pointer->next!=NULL )
       {
           slow_pointer = slow_pointer->next;
           fast_pointer = fast_pointer->next->next;
       }
       return slow_pointer->data;
   }
}
//https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1#

//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    StackNode *temp = new StackNode(x);
    temp->next = top;
    top = temp;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top != NULL)
    {
        StackNode *temp;
        temp = top;
        top = top->next;
        temp->next = NULL;
        return temp->data;
    }
    return -1;
}
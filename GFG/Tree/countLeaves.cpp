//https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

//TC=O(N) SC=O(tree height)
void leaves(Node* root, int &c)
{
    if(!root) return;
    
    if(root->left==NULL && root->right==NULL)
    c++;
    leaves(root->left, c);
    leaves(root->right, c);
}
   
int countLeaves(Node* root)
{
  // Your code here
  int c=0;
  leaves(root, c);
  return c;
}
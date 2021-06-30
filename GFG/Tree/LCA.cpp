//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#

//TC=O(Tree height) SC=O(1)
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(!root) return NULL;
   
   if(n1<root->data && n2<root->data)
       return LCA(root->left, n1, n2);
       
   if(n1>root->data && n2>root->data)
       return LCA(root->right, n1, n2);
   
   return root;
}
//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1#

// METHOD 1
// TC=O(N^2) kyuki recursion ke andar recursion call ho rha h
// SC=O(tree height)
int height(Node* root)
{
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    if(!root) return true;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(abs(lheight-rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    return true;
    
    return false;
}
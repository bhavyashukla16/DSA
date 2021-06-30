//https://practice.geeksforgeeks.org/problems/symmetric-tree/1#

//METHOD 1: Recursion
//TC=O(N) SC=O(Tree height)
bool isMirror(Node* r1, Node* r2)
{
    if(r1==NULL && r2==NULL)
    return true;
    if(r1==NULL || r2==NULL)
    return false;
    
    return (r1->data==r2->data &&
    isMirror(r1->left, r2->right) &&
    isMirror(r1->right, r2->left));
}

// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	// Code here
	return isMirror(root, root);
}

//METHOD 2: Inorder array will be symmetric

//Method 3: using queue
//https://www.cdn.geeksforgeeks.org/check-symmetric-binary-tree-iterative-approach/
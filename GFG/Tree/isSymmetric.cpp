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
bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        TreeNode *leftNode, *rightNode;
        while(!q.empty())
        {
            leftNode=q.front();
            q.pop();
            rightNode=q.front();
            q.pop();
            if(leftNode->val != rightNode->val)
                return false;
            if(leftNode->left && rightNode->right) //if both r present
            {
                q.push(leftNode->left);
                q.push(rightNode->right);
            }
            else if(leftNode->left || rightNode->right) //if one of them is NULL
                return false;
            if(leftNode->right && rightNode->left) 
            {
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            else if(leftNode->right || rightNode->left)
                return false;
        }
        return true;
    }
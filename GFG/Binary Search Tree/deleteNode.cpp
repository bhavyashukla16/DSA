//https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

//TC - O(Height of BST)
//SC - O(Height of BST)
Node* minValueNode(Node* root)
{
    while(root && root->left)
    root = root->left;

    return root;
}
Node* deleteNode(Node* root, int X)
{
    if(!root)
    return root;

    if(X > root->data)
    root->right = deleteNode(root->right, X);

    else if(X < root->data)
    root->left = deleteNode(root->left, X);

    else{
        //node has no children
        if(!root->left && !root->right)
        return NULL;

        //node has only 1 child
        else if(!root->left)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        //node has both children
        Node* temp = minValueNode(root->right); //inorder successor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
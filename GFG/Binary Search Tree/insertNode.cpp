//https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

//TC - O(Height of BST)
//SC - O(Height of BST)
// Function to insert a node in a BST.
Node* insert(Node* root, int Key) {
    // Your code here
    if(!root)
    return new Node(Key);
    
    if(Key > root->data)
    root->right = insert(root->right, Key);
    
    else if(Key < root->data)
    root->left = insert(root->left, Key);
    
    return root; //return root if Key == root->data
}
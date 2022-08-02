//https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1

//TC - O(Height of BST)
//SC - O(1)
bool search(Node* root, int x) {
    // Your code here
    if(!root)
    return false;
    
    if(root && root->data == x)
    return true;
    
    if(x > root->data)
    return search(root->right, x);
    
    else if(x < root->data)
    return search(root->left, x);
    
}
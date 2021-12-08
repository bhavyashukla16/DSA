//https://practice.geeksforgeeks.org/problems/mirror-tree/1#

//METHOD 1: Recursion
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node) return;
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
        mirror(node->right);
        mirror(node->left);
    }

//METHOD 2: BFS
// Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node) return;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            swap(curr->left, curr->right);
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
    }
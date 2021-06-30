//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

//TC=O(N) SC=O(tree height)
//The diameter of a tree T is the largest of the following quantities:
//   1) the diameter of T's left subtree.
//   2) the diameter of T's right subtree.
//   3) the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

int height(Node* root)
    {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    int diameter(Node* root) {
        // Your code here
        if(!root) return 0;
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        int ldiameter = diameter(root->left);
        int rdiameter = diameter(root->right);
        
        return max(lheight+ rheight +1, max(ldiameter, rdiameter));
    }
//https://practice.geeksforgeeks.org/problems/check-for-bst/1#

//METHOD 1: Inorder traversal should be a sorted array
//TC=O(N) SC=O(N)
vector<int> v;
    void inOrder(Node* root)
    {
        if(!root) return;
        
        inOrder(root->left);
        v.push_back(root->data);
        inOrder(root->right);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        inOrder(root);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
            return false;
        }
        return true;
    }

//METHOD 2: CORRECT AND EFFICIENT
// TC=O(N) SC=O(tree height)
// keep track of the min and max values for the left n right subtrees
bool isBSTUtil(Node* root, int min, int max)
    {
        if(!root) return true;
        
        if(root->data < min || root->data > max)
        return false;
        
        return isBSTUtil(root->left, min, root->data-1) &&
        isBSTUtil(root->right, root->data+1, max);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
       return isBSTUtil(root, INT_MIN, INT_MAX);
    }

//METHOD 4: istead of keeping track of min n max values use left n right NULL pointers
// TC=O(N) SC=O(Tree height)
bool isBSTUtil(Node* root, Node* l, Node* r)
    {
        if(!root) return true;
        
        if(l!=NULL && root->data <= l->data)
        return false;
        
        if(r!=NULL && root->data >= r->data)
        return false;
        
        return isBSTUtil(root->left, l, root) &&
        isBSTUtil(root->right, root, r);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return isBSTUtil(root, NULL, NULL);
    }

//METHOD 2: SIMPLE BUT WRONG 
// will fail in 3 2 5 1 4, all the values of the left subtree should be < root which this code does not check
bool isBST(Node* root) 
    {
        // Your code here
        if(!root) return true;
        if(root->left!=NULL && root->left->data >= root->data)
        return false;
        if(root->right!=NULL && root->right->data <= root->data)
        return false;
        
        return ( isBST(root->left) && isBST(root->right) );
    }



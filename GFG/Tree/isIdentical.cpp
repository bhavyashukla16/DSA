//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1#

//METHOD 1: Recursion
//TC=O(N) SC=O(Tree height)
bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)
        return true;
        if(r1==NULL || r2==NULL)
        return false;
        
        return (r1->data==r2->data && 
        isIdentical(r1->left, r2->left) && 
        isIdentical(r1->right, r2->right));
    }


//METHOD 2: Inorder + Preorder/Postorder identify a tree 
//TC=O(N) SC=O(1)
void inOrder(Node* root, string in)
    {
        if(!root) return;
        inOrder(root->left, in);
        in+=(char)root->data + 48;
        inOrder(root->right, in);
    }
    void preOrder(Node* root, string pre)
    {
        if(!root) return;
        pre+=(char)root->data + 48;
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)
        return true;
        if(r1==NULL || r2==NULL)
        return false;
        
        string in1="", in2="";
        inOrder(r1, in1);
        inOrder(r2, in2);
        //cout<<in1<<" "<<in2<<" ";
        if(in1!=in2)
        return false;
        
        string pre1="", pre2="";
        preOrder(r1, pre1);
        preOrder(r2, pre2);
        
        if(pre1!=pre2)
        return false;
        
        return true;
    }
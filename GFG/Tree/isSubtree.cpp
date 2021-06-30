//https://practice.geeksforgeeks.org/problems/check-if-subtree/1

//METHOD 1: 
//TC=O(N*M) where m and n are the no. of nodes in the 2 trees
bool isIdentical(Node* root1, Node* root2)
  {
      if(root1==NULL && root2==NULL)
      return true;
      if(root1==NULL || root2==NULL)
      return false;
      
      return root1->data==root2->data &&
      isIdentical(root1->left, root2->left) &&
      isIdentical(root1->right, root2->right);
  }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(S==NULL)
        return true;
        
        if(T==NULL)
        return false;
        
        if(isIdentical(T, S))
        return true;
        
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }

//METHOD 2: Inorder and Preorder/Postorder uniquely identifies a tree! 
//So calculate both foe both trees n check if one is substring of other or not
void inOrder(Node* root, string &in)
    {
        if(!root) return;
        inOrder(root->left, in);
        in+=(char)root->data + 48;
        inOrder(root->right, in);
    }
    void preOrder(Node* root, string &pre)
    {
        if(!root) return;
        pre+=(char)root->data + 48;
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(S==NULL)
        return true;
        
        if(T==NULL)
        return false;
        
        string in1="", in2="";
        inOrder(T, in1);
        inOrder(S, in2);
        //cout<<in1<<" "<<in2<<" ";
        if(in1.find(in2)==string::npos)
        return false;
        
        string pre1="", pre2="";
        preOrder(T, pre1);
        preOrder(S, pre2);
        
        if(pre1.find(pre2)==string::npos)
        return false;
        
        return true;
    }
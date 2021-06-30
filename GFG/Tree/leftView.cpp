//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// METHOD 1: RECURSION
// TC=O(N) SC=O(N) stack space for recursive call

vector<int> v;
 void leftViewUtil(Node *root, int level, int *max_level)
 {
     if(root == NULL) return;
     
     if(*max_level < level)
     {
         v.push_back(root->data);
         //cout<<root->data<<" ";
         *max_level = level;
     }
     
     leftViewUtil(root->left, level+1, max_level);
     leftViewUtil(root->right, level+1, max_level);
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   int max_level = 0;
   v.clear();
   leftViewUtil(root, 1, &max_level);
   return v;
}

// METHOD 2: QUEUE
// TC=O(N) SC=O(N)

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> v;
   if(!root) return v;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       int n = q.size();
       for(int i=1;i<=n;i++) //to travel all nodes of the current level
       {
           Node *temp = q.front();
           q.pop();
           if(i==1) // har level ka 1st node 
           v.push_back(temp->data);
           
           if(temp->left!=NULL)
           q.push(temp->left);
           
           if(temp->right!=NULL)
           q.push(temp->right);
       }
   }
   return v;
}
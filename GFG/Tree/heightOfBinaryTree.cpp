//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

//METHOD 1: Recursion
//TC=O(N) SC=O(Tree height)
int height(struct Node* node)
{
    //code here
    if(!node) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

//METHOD 2: using queue
//TC=O(N) SC=O(N)
int height(struct Node* node){
        // code here 
        if(!node) return 0;
        queue<Node*> q;
        q.push(node);
        int height=0;
        while(1)
        {
            int nodeCountInOneLevel=q.size();
            if(nodeCountInOneLevel==0) 
            return height;
            
            height++;
            
            while(nodeCountInOneLevel > 0)
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
                nodeCountInOneLevel--;
            }
        }
    }
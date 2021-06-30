//https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1#

//TC=O(N) SC=O(max nodes in a level)
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(!root) return ans;
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(temp->right) //first right is pushed so that left is printed first, stack h na
            s2.push(temp->right);
            
            if(temp->left)
            s2.push(temp->left);
        }
        while(!s2.empty())
        {
            Node* temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            if(temp->left)
            s1.push(temp->left);
            
            if(temp->right)
            s1.push(temp->right);
        }
    }
    return ans;
}
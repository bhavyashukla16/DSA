//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

//TC=O(N) SC=O(tree diameter)
void setHD(Node* root, int hd, int level, map<int, pair<int,int> >&mp)
{
    if(!root) return;
    
    if(mp.find(hd)==mp.end()) //if a node at that HD is not present 
    mp[hd] = {root->data, level};
    else
    {
        if(level>=mp[hd].second) //if the curr level of node is >= the level of node already present update
        {
            mp[hd].first = root->data;
            mp[hd].second = level;
        }
    }
    setHD(root->left, hd-1, level+1, mp);
    setHD(root->right, hd+1, level+1, mp);
}
//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
   // Your Code Here
   vector<int> ans;
   map<int, pair<int,int> >mp; // <hd, {root->data, level}>
   setHD(root, 0, 0, mp);
   map<int, pair<int,int> >::iterator it;
   for(it=mp.begin(); it!=mp.end(); it++)
   {
       ans.push_back(it->second.first);
   }
   return ans;
}
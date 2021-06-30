//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

//METHOD 1: 1) Find the max n min horizontal distance w.r.t root in a binary tree
//          2) Run a loop from min to max value of hd n print all nodes having same hd
//TC=O(N^2) SC=O(1)
findMinMax(root, min, max, hd)
    if(!root) return;
    if(hd < *min)
    *min = hd;
    else if(hd > *max)
    *max = hd;

    findMinMax(root->left, min, max, hd-1);
    findMinMax(root->root, min, max, hd+1);

printVerticalLine(root, line_no, hd)
    if(!root) return;
    if(hd == line_no)
    cout<<root->data;

    printVerticalLine(root->left, line_no, hd-1);
    printVerticalLine(root->right, line_no, hd+1);

void verticalOrder(Node *root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
  
    for(int line_no=min; line_no<=max; line_no++)
        printVerticalLine(root, line_no, 0);
}

//METHOD 2: using Hash Table to store all the nodes at a particular Horizontal distance(HD)
//TC=O(N) SC=O(N)
void setHD(Node* root, int hd, map<int, vector<int>> &mp)
    {
        if(!root) return;
        mp[hd].push_back(root->data);
        setHD(root->left, hd-1, mp);
        setHD(root->right, hd+1, mp);
    }
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int, vector<int>> mp;
        setHD(root, 0, mp);
        map< int,vector<int> > :: iterator it;
        for (it=mp.begin(); it!=mp.end(); it++)
        {
            for(int i=0; i<it->second.size(); i++)
            ans.push_back(it->second[i]);
        }
        return ans;
    }
//https://leetcode.com/problems/binary-tree-paths/
//TC=O(N)

void solve(TreeNode* root, string s, vector<string>&v) {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            s+=to_string(root->val);
            v.push_back(s);
            return;
        }
        s+=to_string(root->val);
        s+="->";
        solve(root->left, s, v);
        solve(root->right, s, v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        solve(root, "", v);
        return v;
    }
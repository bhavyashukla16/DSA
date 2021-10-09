//https://leetcode.com/problems/minimum-depth-of-binary-tree/
//TC=O(N) SC=O(Tree height)
int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right))+1;
        else if(root->left)
            return minDepth(root->left)+1;
        
        return minDepth(root->right)+1;
    }
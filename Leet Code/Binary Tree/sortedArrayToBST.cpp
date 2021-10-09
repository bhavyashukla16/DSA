//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//TC=O(N) sc=o(tree height)

TreeNode* solve(vector<int>& nums, int start, int end) {
        if(start>end)
            return NULL;
        int mid = (end+start)/2;
        TreeNode *root= new TreeNode(nums[mid]);
        root->left = solve(nums, start, mid-1);
        root->right = solve(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
int findDuplicate(vector<int>& nums) {
        set<int> s; int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else
            ans = nums[i];
        }
        return ans;
    }
//https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

//WORKING
//TC - O(N^k-2 * N) i.e O(N^k-1)
//SC  -O(N*k)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k)
    {
        vector<vector<int>> res;
        if(start == nums.size())
            return res;
        
        long long avg_val = target/k;
        if(nums[start]>avg_val || nums.back()<avg_val)
            return res;
        
        if(k == 2)
            return twoSum(nums, target, start);
        
        for(int i=start;i<nums.size();i++)
        {
            if(i==start || nums[i]!=nums[i-1])
            {
                vector<vector<int>> output = kSum(nums, target-nums[i], i+1, k-1);
                for(vector<int> subset : output)
                {
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), subset.begin(), subset.end());
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start)
    {
        vector<vector<int>> res;
        int l=start, r=nums.size()-1;
        
        while(l<r)
        {
            long long curr_sum=nums[l]+nums[r];
            if(curr_sum<target || (l>start && nums[l]==nums[l-1]))
                l++;
            else if(curr_sum>target || (r<nums.size()-1 && nums[r]==nums[r+1]))
                r--;
            else
                res.push_back({nums[l++], nums[r--]});
        }
        return res;
    }

//TC=O(N^3) SC=O(N^2)
//NOT WORKING
int compare( const void *a, const void *b)
    {
        return *(int *)a - *(int *)b ;
    }
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        qsort(&arr[0], arr.size(), sizeof(int), compare);
        
        vector<vector<int> > v;
        
        int n = arr.size();
        int l,r;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                l=j+1;
                r=n-1;
                
                while(l<r)
                {
                    if(arr[i]+arr[j]+arr[l]+arr[r] == k)
                    {
                        vector<int> v1 = {arr[i], arr[j], arr[l], arr[r]};
                        if(v.size()>0 && v[v.size()-1] == v1)
                        continue;
                        
                        v.push_back(v1);
                        l++;
                        r--;
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[r] < k)
                    l++;
                    else
                    r--;
                }
            }
        }
        
        return v;
    }
};
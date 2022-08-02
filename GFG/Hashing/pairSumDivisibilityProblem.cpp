//https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

//TC=O(N) SC=O(N)
bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n&1)
        return false;
        
        map<int, int> mp;
        int c=0;
        for(int i=0;i<n;i++)
        mp[(nums[i]%k + k) % k]++;
        
        int rem;
        for(int i=0;i<n;i++)
        {
            rem = (nums[i]%k + k) % k;
            if(rem*2 == k || rem == 0)
            {
                if(mp[rem]&1) //they have to be even to pair up among themselves
                return false;
                else
                {
                    c+=mp[rem]/2;
                    mp[rem]=0;
                }
            }
            
            else if(mp.find(k-rem)!=mp.end() && mp[k-rem]>0 && mp[rem]>0)
            {
                c++;
                mp[k-rem]--;
                mp[rem]--;
            }
        }
        if(c==n/2)
        return true;
        
        return false;
    }
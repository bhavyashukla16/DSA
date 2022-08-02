//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

//TC=O(N) SC=O(N)
ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll c=0;
        map<ll,ll> mp;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sum+=arr[i];
            
            if(sum==0)
            c++;
            
            if(mp.find(sum)!=mp.end())
            {
                c+=mp[sum];
            }
            
            mp[sum]++;
        }
        return c;
    }
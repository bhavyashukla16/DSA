//https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1/#

//TC=O(N) SC=O(N)
int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        int ans=0; int sum=0;
        map<int,int> mp;
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];
            
            if(sum==k)
            ans++;
            
            if(mp.find(sum-k)!=mp.end())
            ans+=mp[sum-k];
            
            mp[sum]++;
        }
        return ans;
    }
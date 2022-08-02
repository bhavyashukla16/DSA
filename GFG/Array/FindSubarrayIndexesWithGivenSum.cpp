//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

//TC - O(N)
//SC - O(1)
vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> ans;
        int l=0, r=0;
        long long csum=0;
        while(r<n)
        {
            csum+=arr[r];
            while(csum>s && l<n)
            {
                csum-=arr[l++];
            }
            if(csum==s)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            r++;
        }
        if(ans.size()==0) ans.push_back(-1);
        return ans;
    }
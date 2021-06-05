//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

int maxLen(int A[], int n)
{
    // Your code here
    map<int,int> mp;
    int sum=0, maxLen=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        
        if(sum==0)
        maxLen=i+1;
        
        if(mp.find(sum)!=mp.end())
            maxLen = max(maxLen, i-mp[sum]);
        else
            mp[sum]=i;
    }
    
    return maxLen;
}
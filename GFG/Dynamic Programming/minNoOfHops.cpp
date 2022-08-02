//https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1

//TC - O(N)
//SC - O(N)
long long countWays(int n)
    {
        
        // your code here
        long long dp[n+1];
        dp[0]=0, dp[1]=1, dp[2]=2, dp[3]=4;
        
        for(int i=4;i<n+1;i++)
        {
            dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000007;
        }
        return dp[n];
    }
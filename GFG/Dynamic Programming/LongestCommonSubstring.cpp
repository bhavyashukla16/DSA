//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

//TC - O(N*N)
//SC - O(N*N)
int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        int ans=0;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
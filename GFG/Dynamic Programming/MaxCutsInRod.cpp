//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

//NOT WORKING
 int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int length[3] = {x,y,z};
        int dp[4][n+1];
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
            }
        }
         for(int i=1;i<4;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(length[i-1]<=j)
                dp[i][j] = max(dp[i][j-length[i-1]]+1, dp[i-1][j]);
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[3][n];
    }
//https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1

//Correct
int minOperation(int n)
    {
        //code here.
        int dp[1000005];
        dp[0]=0, dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i&1)
            dp[i] = dp[i-1]+1;
            else
            dp[i] = min(dp[i-1], dp[i/2]) +1;
        }
        return dp[n];
    }

//TLE using Recursion
int recursion(int x, int n, int count)
  {
      if(x==n) return count;
      
      if(x > n) return INT_MAX-1;
      
      return min(recursion(x+1, n, count+1), recursion(x*2, n, count+1));
  }
    int minOperation(int n)
    {
        //code here.
        return recursion(1, n, 1);
    }
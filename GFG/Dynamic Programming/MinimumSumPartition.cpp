//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

//TC - O(N*N)
//SC - O(N*N)
int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0, min_diff=INT_MAX;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<sum+1;j++)
	        {
	            if(i==0)
	            dp[i][j]=false;
	            if(j==0)
	            dp[i][j]=true;
	        }
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	            if(arr[i-1]<=j)
	            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            else
	            dp[i][j] = dp[i-1][j];
	        }
	    }
	    for(int i=1;i<sum+1;i++)
	    {
	        if(dp[n][i] == true)
	        min_diff = min(min_diff, abs(sum-2*i));
	    }
	    return min_diff;
	} 
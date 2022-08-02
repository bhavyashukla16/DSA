//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

//TC - O(N*N)
//SC - O(N)
int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int sum[n];
	    for(int i=0;i<n;i++)
	    sum[i]=arr[i];
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j])
	            sum[i] = max(sum[i], sum[j]+arr[i]);
	        }
	    }
	    sort(sum, sum+n);
	    return sum[n-1];
	}
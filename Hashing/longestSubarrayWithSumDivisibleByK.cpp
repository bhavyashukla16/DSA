//https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1

//TC=O(N) SC=O(N)
int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int,int> mp;
	    int sum=0; int rem;
	    int max_len=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        rem = ((sum%k)+k)%k; //handles -ve numbers as well
	        if(rem==0)
	        max_len = max(max_len, i+1);
	        
	        else if(mp.find(rem)!=mp.end())
	        max_len = max(max_len, i-mp[rem]);
	        
	        else mp[rem]=i; //woh rem nhi mila tb uska index map me daalenge so that we get the first index i.e. longest length
	    }
	    return max_len;
	}
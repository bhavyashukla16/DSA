//https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1#

//METHOD 1: a-b = (sum1+sum2)/2
//TC=O(N*M) NAIVE
int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sum1=0, sum2=0;
        for(int i=0;i<n;i++)
        sum1+=A[i];
        
        for(int i=0;i<m;i++)
        sum2+=B[i];
        
        if((sum1+sum2)&1)
        return -1;
        
        int k = abs(sum1-sum2)/2;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int d = sum1>sum2 ? A[i]-B[j] : B[j]-A[i] ;
                if(d==k)
                return 1;
            }
        }
        
        return -1;
	}

//METHOD 2
// Time Complexity :- 
// If arrays are sorted : O(n + m) 
// If arrays aren’t sorted : O(nlog(n) + mlog(m))
int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sum1=0, sum2=0;
        for(int i=0;i<n;i++)
        sum1+=A[i];
        
        for(int i=0;i<m;i++)
        sum2+=B[i];
        
        if((sum1+sum2)&1)
        return -1;
        
        int k = (sum1-sum2)/2;
        sort(A, A+n); 
        sort(B, B+m);
        
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(A[i]-B[j] == k)
            return 1;
            
            else if(A[i]-B[j] < k)
            i++;
            
            else
            j++;
        }
        
        return -1;
	}

//METHOD 3: Hash the first array then loop through the 2nd array n search for B[i]+k in the hash
//k = (sum1-sum2)/2
//TC = O(N+M) FASTEST
int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sum1=0, sum2=0;
        for(int i=0;i<n;i++)
        sum1+=A[i];
        
        for(int i=0;i<m;i++)
        sum2+=B[i];
        
        if((sum1+sum2)&1)
        return -1;
        
        int k = (sum1-sum2)/2;
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[A[i]]++;
        
        for(int i=0;i<m;i++)
        {
            if(mp.find(B[i]+k)!=mp.end())
            return 1;
        }
        
        return -1;
	}
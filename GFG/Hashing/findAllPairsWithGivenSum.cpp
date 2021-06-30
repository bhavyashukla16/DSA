//https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1#

//TC=O(Nlog N) SC=O(N)
vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here  
        vector<pair<int,int> > v;
        map<int,int> mp;
        for(int i=0;i<N;i++)
        mp[A[i]]++;
        
        for(int i=0;i<M;i++)
        {
            if(mp.find(X-B[i])!=mp.end())
            v.push_back({X-B[i], B[i]});
        }
        
        sort(v.begin(), v.end());
        return v;
    }
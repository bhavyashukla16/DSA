//https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1#

//TC=O(N+M) SC=O(N)
int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        
        for(int i=0;i<m;i++)
        {
            if(mp.find(b[i])!=mp.end() && mp[b[i]]>0)
            {
                ans++;
                mp[b[i]]=0;
            }
        }
        return ans;
    }
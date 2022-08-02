//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//METHOD 1: Initialise 1 in the dp array- ans will be 1 only if no changes are made (Eg- when a decreasing array is given)
//for any index, traverse the array from 0 to before that to see if a[i]>a[j] if so update dp[i]=max(dp[i], dp[j]+1)
//TC - O(N*N)
//SC - O(N)
int longestSubsequence(int n, int a[])
    {
       // your code here
       int dp[n];
       for(int i=0;i<n;i++) //initialization
       dp[i]=1;
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(a[i] > a[j])
               dp[i] = max(dp[i], dp[j]+1);
           }
       }
       
       sort(dp, dp+n);
       return dp[n-1];
    }

//METHOD 2: Make it a LCS (Longest Common Subsequence) problem
//Add all unique elements to an array and sort it
//Now ur answer will be the LCS of the original array and this array
//TC - O(N*N)
//SC - O(N*N)
int longestSubsequence(int n, int a[])
    {
       // your code here
       set<int> s;
       for(int i=0;i<n;i++) 
       s.insert(a[i]);
       
       vector<int> v;
       for(auto x : s)
       v.push_back(x);
       
       int dp[n+1][v.size()+1];
       
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<v.size()+1;j++)
           {
               if(i==0 || j==0)
               dp[i][j]=0;
           }
       }
       
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<v.size()+1;j++)
           {
               if(a[i-1]==v[j-1])
               dp[i][j]=dp[i-1][j-1]+1;
               
               else
               dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
           }
       }
       
       return dp[n][v.size()];
    }
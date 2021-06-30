//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

//METHOD 1: Without Hashing
//TC=O(N LogN) SC=O(1)
int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int max_len=0;
      int l=1; //cause min ans 1 toh hoga hi
      sort(arr, arr+N);
      for(int i=1;i<N;i++)
      {
          if(arr[i]-arr[i-1]==0)
          continue;
          if(arr[i]-arr[i-1]==1)
          l++;
          else
          {
              max_len=max(max_len, l);
              l=1;
          }
      }
      return max(max_len, l);
    }
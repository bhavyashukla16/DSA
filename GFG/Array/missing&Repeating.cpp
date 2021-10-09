//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

//METHOD 1: using Freq array
//TC=O(N) SC=O(N)
int *findTwoElement(int *arr, int n) {
        // code here
        static int ans[2]={0};
        int freq[n+1]={0};
        sort(arr, arr+n);
        for(int i=0;i<n;i++)
        freq[arr[i]]++;
            
        for(int i=1;i<n+1;i++)
        {
            if(freq[i]==0)
            ans[1] = i;
            else if(freq[i]==2)
            ans[0] = i;
        }
        return &ans[0];
    }

//METHOD 2: Use array values as indexes n mark them visited
//TC=O(N) SC=O(1)
int *findTwoElement(int *arr, int n) {
        // code here
        static int ans[2]={0};
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<0)
            ans[0] = abs(arr[i]);
            else
            arr[abs(arr[i])-1]*=-1;
        }
        for(int i=0;i<n;i++)
        if(arr[i]>0)
        ans[1] = i+1;
        return &ans[0];
    }
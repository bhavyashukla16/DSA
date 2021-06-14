//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

//TC=O(N^2) SC=O(1)
bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        int l,r;
        for(int i=0;i<n-2;i++)
        {
            l=i+1; r=n-1;
            while(l<r)
            {
                if(A[i]+A[l]+A[r]==X)
                return true;
                
                else if(A[i]+A[l]+A[r]<X)
                l++;
                
                else r--;
            }
        }
        return false;
    }
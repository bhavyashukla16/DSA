//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

//METHOD 1: Hashmap
//TC=O(N) SC=O(N)

//METHOD 2: sorting
//TC=O(N logN) SC=O(1)
int majorityElement(int a[], int size)
    {
        // your code here
        sort(a,a+size);
        int ans=-1;
        int c=1;
        // for(int i=0;i<size;i++)
        // cout<<a[i]<<" ";
        for(int i=1;i<size;i++)
        {
            if(a[i]!=a[i-1])
            {
                if(c>size/2)
                {
                    ans=a[i-1];
                }
                c=1;
            }
            else c++;
        }
        if(c>size/2)
        ans=a[size-1];
        return ans;
    }
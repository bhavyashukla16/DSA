//https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

//TC=O(N^3) SC=O(N^2)
//NOT WORKING
int compare( const void *a, const void *b)
    {
        return *(int *)a - *(int *)b ;
    }
class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        qsort(&arr[0], arr.size(), sizeof(int), compare);
        
        vector<vector<int> > v;
        
        int n = arr.size();
        int l,r;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                l=j+1;
                r=n-1;
                
                while(l<r)
                {
                    if(arr[i]+arr[j]+arr[l]+arr[r] == k)
                    {
                        vector<int> v1 = {arr[i], arr[j], arr[l], arr[r]};
                        if(v.size()>0 && v[v.size()-1] == v1)
                        continue;
                        
                        v.push_back(v1);
                        l++;
                        r--;
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[r] < k)
                    l++;
                    else
                    r--;
                }
            }
        }
        
        return v;
    }
};
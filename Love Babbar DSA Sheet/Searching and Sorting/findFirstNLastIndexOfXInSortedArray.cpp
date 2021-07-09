//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

//TC: O(N) SC:O(1)
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v;
    int f=-1,l=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            if(f==-1)
            f = i;
            l = i;
        }
    }
    v.insert(v.begin(), {f, l});
    return v;
}
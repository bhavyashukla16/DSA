// clockwise by 1
// TC: O(n)
// SC: O(1)
void rotate(int arr[], int n)
{
    int p=arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=p;
}

//clockwise by k
void rotate(int arr[], int n, int k)
{
    vector<int> v;
    for(int i=n-k;i<n;i++)
    v.push_back(arr[i]);

    for(int i=0;i<n-k;i++)
    v.push_back(arr[i]);

    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}
//https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

//TC=O(N) SC=O(N)

string isSubset(int a1[], int a2[], int n, int m) {
    map<int,int> mp;
    for(int i=0;i<n;i++)
    mp[a1[i]]++;
    
    for(int i=0;i<m;i++)
    {
        if(mp.find(a2[i])==mp.end())
        return "No";
    }
    return "Yes";
}
//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

// Two-pointer technique fails!
// 1 1 5 7
// if there r multiple same numbers then it will not give the correct answer therefore use map
// So, two-pointer technique will only answer True/False, if such a pair is present in array or not

// Correct Approach

int getPairsCount(int arr[], int n, int k) {
        
        map<int, int> mp;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            ans+=mp[k-arr[i]];
            
            if(k-arr[i]==arr[i]) // to remove (arr[i], arr[i]) from the count
            ans--;
        }
        
        return ans/2; // every pair will be counted twice
    }
//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//METHOD 1: Sorting (If all elements r distinct)
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        sort(arr+l, arr+r+1);
        return arr[l+k-1];
}

// METHOD 2: Quick sort (If all elements r distinct)

// METHOD 3: Ordered map (Works better if all elements r not distinct else gives TLE)
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        map<int, int>mp;
        for(int i=l; i<=r; i++)
        mp[arr[i]]++;
        
        int freq=0;
        for(auto it : mp)
        {
           freq+=it.second;
           if(freq>=k)
           return it.first;
        }
        return -1;
    }
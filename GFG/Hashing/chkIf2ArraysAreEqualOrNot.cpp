//https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1#

//METHOD 1: Sort the arrays and chk every element
//TC=O(N Log N) SC=O(1)


//METHOD 2: Hashing 
//TC=O(N) SC=O(N)

//Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        map<int,int> mp;
        for(int i=0;i<A.size();i++)
            mp[A[i]]++;
            
        for(int i=0;i<B.size();i++)
        {
            if(mp.find(B[i])==mp.end() || mp[B[i]]==0)
            return false;
            
            mp[B[i]]--;
        }
        
        return true;
    }
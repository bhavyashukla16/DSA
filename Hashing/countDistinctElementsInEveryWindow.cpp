//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#

//TC=O(N) SC=O(N)
vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        map<int,int> mp;
        vector<int> v;
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(mp[A[i]]==0)
            count++;
            mp[A[i]]++;
        }
        
        v.push_back(count);
        int l=0;
        for(int i=k;i<n;i++)
        {
            if(mp[A[l]]==1) //if the elemnt to be removed from the window has occured only once
            {
                count--;
                mp[A[l]]--;
            }
            else //if not then it must have occured in the current window
            mp[A[l]]--;
            
            l++; //to move to the next element to be removed from the window
            
            if(mp[A[i]]==0) //if the new element is not present in map
            {
                count++;
                mp[A[i]]++;
            }
            else
            mp[A[i]]++;
            
            v.push_back(count);
        }
        
        return v;
    }
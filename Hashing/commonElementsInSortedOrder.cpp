//https://practice.geeksforgeeks.org/problems/common-elements5420/1#

//TC=O(M+N*log N) SC=O(N)
vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        map<int,int> mp;
        vector<int> v;
        for(int i=0;i<v1.size();i++)
            mp[v1[i]]++;
        
        for(int i=0;i<v2.size();i++)
        {
            if(mp.find(v2[i])!=mp.end() && mp[v2[i]]!=0)
            {
                v.push_back(v2[i]);
                mp[v2[i]]--; //jitni baar element pehle aa chuka h utni hi baar yaha bhi print hoga
            }
        }
        
        sort(v.begin(), v.end());
        
        return v;
    }
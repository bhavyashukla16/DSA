//https://practice.geeksforgeeks.org/problems/uncommon-characters4932/1#

string UncommonChars(string A, string B)
        {
            // code here
            string ans="";
            map<char,int> mp;
            for(int i=0;i<A.length();i++)
            {
                mp[A[i]]=1;
            }
            
            for(int i=0;i<B.length();i++)
            {
                if(mp[B[i]]==1)
                mp[B[i]]=-1; //for common characters
                else if(mp[B[i]]==-1)
                continue;
                else
                mp[B[i]]=2;
            }
            
            for(auto it=mp.begin(); it!=mp.end(); it++)
            {
                if(it->second == 1 || it->second == 2) //with value 1 or 2 are the uncommon ones
                ans+=it->first;
            }
            
            if(ans=="")
            return "-1";
        
            return ans;
        }
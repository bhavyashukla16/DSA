//https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1

//TC=O(N)
int minIndexChar(string str, string patt)
    {
        // Your code here
        map<char, int> mp;
        int index=str.length()-1;
        int c=0;
        for(int i=0;i<str.length();i++)
        {
            if(mp[str[i]]==0) //sbka index store krlo
            mp[str[i]]=i+1;
        }
        
        for(int i=0;i<patt.length();i++)
        {
            size_t f= str.find(patt[i]);
            if(f!=string::npos) //agar woh char mil gya toh index me minimum value store krlo
            index=min(index, int(f));
            else
            c++;
        }
        
        if(c==patt.length())
        return -1;
        else return index;
    }
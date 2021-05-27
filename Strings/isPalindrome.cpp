// METHOD 1: 2 pointer
int isPlaindrome(string S)
	{
	    // Your code goes here
	    int l=0, r=S.length()-1;
    
        while(l<r)
        {
            if(S[l++]!=S[r--])
            return 0;
        }
        
        return 1;
    }

// METHOD 2: Recursion

int isPlaindrome(string S)
	{
	    // Your code goes here
	    int l=0, r=S.length()-1;

            return isPali(S,l,r);
    }
    
    int isPali(string S, int l, int r) {
        
        if(l>=r)
        return 1;
        
        if(S[l]!=S[r])
        return 0;
        
        return isPali(S, l+1, r-1);
        
        return 1;
    }
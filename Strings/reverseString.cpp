//METHOD 1: reverse for loop (FASTEST)

//METHOD 2: 2 pointers

void reverseString(vector<char>& s) {
        
        int l=0, r=s.size()-1;
        while(l<r)
        {
            swap(s[l], s[r]);
            l++; r--;
        }
    }

//METHOD 3: reverse(s.begin(), s.end()) (SLOWEST)

//METHOD 4: recursion (SLOWEST)
void reverseString(vector<char>& s) {
        
        int l=0, r=s.size()-1;
        rev(s, l, r);
    }
    
    void rev(vector<char>& s, int l, int r){
        
        if(l>=r)
            return;
        
        swap(s[l], s[r]);
        return rev(s, l+1, r-1);
    }
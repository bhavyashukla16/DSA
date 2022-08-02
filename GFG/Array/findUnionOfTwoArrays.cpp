 // TC: O(n+m)log(n+m)
 // SC: O(n+m)
 // METHOD: 1
 // 1.53 sec
 int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int> s;
        for(int i=0;i<n;i++)
        s.insert(a[i]);
        
        for(int i=0;i<m;i++)
        s.insert(b[i]);
        
        return s.size();
    }

// 1.27 sec
//METHOD: 2
//map will also store distinct elements
int doUnion(int a[], int n, int b[], int m)  {
        //code here
        map<int, int> mp;
        for(int i=0;i<n;i++)
        mp[a[i]]=i; 
        
        for(int i=0;i<m;i++)
        mp.insert({b[i], i}); //also used
        
        return mp.size();
    }

int intersection(int a[], int n, int b[], int m) {

        map<int, int> mp;
        for(int i=0;i<n;i++)
        mp[a[i]]=i; 
        
        for(int i=0;i<m;i++)
        mp.insert({b[i], i}); //also used
        
        return n+m-mp.size(); // for count //WRONG Eg- 1 2 2 and 1 3

        // for printing elements
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i])==mp.end())
            cout<<a[i]<<" ";
        }
        for(int i=0;i<m;i++)
        {
            if(mp.find(b[i])==mp.end())
            cout<<b[i]<<" ";
        }
}

//METHOD 3: Sorting and searching (Naive)

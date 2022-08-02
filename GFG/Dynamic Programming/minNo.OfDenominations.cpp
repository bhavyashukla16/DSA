//https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

//TC - O(N)
//SC - O(N)
vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        int notes[10] = {2000,500,200,100,50,20,10,5,2,1};
        for(int i=0;i<10;i++)
        {
            if(N/notes[i]!=0)
            {
                ans.insert(ans.begin(), N/notes[i], notes[i]);
                N=N%notes[i];
                if(N==0) break;
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
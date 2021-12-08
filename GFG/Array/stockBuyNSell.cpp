//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#

//Method 1: Keeping a track of maximum difference bet prices
//TC = O(N)
 vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> ans;
        int i=0;
        while(i<n)
        {
            while(i<n-1 && A[i+1]<=A[i])
            i++;
            
            if(i==n-1) break;
            
            int buy = i++;
            
            while(i<n && A[i]>=A[i-1])
            i++;
            
            int sell = i-1;
            
            vector<int> v;
            v.push_back(buy);
            v.push_back(sell);
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }

//METHOD 2: Valley peak approach
//TC = O(N)
int max_profit = 0;
for(int i=1;i<n;i++)
{
    if(prices[i]>prices[i-1])
    max_profit+= prices[i]-prices[i-1];
}
return max_profit;
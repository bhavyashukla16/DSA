//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// METHOD 1: Brute Force
// TLE O(n^2)

//METHOD 2

int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int min_ele = prices[0]; // to keep track of the minimum element
        for(int i=1;i<n;i++)
        {
            min_ele = min(min_ele, prices[i]);
            profit = max(profit, prices[i]-min_ele); //ek baar minimum element aa gya toh profit ka track rakh hi skte h
        }
        return profit;
    }

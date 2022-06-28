class Solution {
public:
    
    int helper(vector<int>& prices,int buy, int cap,int ind, int n,vector<vector<vector<int>>>& dp) {
        if(cap==0) return 0;
        if(ind == n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy==1)
            profit = max((-prices[ind] + helper(prices, 0, cap,ind+1,n, dp)), 0 + helper(prices,1, cap, ind+1, n,dp));
        else
            profit = max((prices[ind] + helper(prices, 1, cap-1, ind+1, n,dp)), 0+ helper(prices,0,cap,ind+1,n,dp));
        return dp[ind][buy][cap] =  profit;                 
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,1,2,0,n,dp);
    }
};
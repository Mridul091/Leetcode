class Solution {
public:
    
    // int helper(vector<int>& prices,int buy, int cap,int ind, int n,vector<vector<vector<int>>>& dp) {
    //     if(cap==0) return 0;
    //     if(ind == n) return 0;
    //     if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    //     int profit = 0;
    //     if(buy==1)
    //         profit = max((-prices[ind] + helper(prices, 0, cap,ind+1,n, dp)), 0 + helper(prices,1, cap, ind+1, n,dp));
    //     else
    //         profit = max((prices[ind] + helper(prices, 1, cap-1, ind+1, n,dp)), 0+ helper(prices,0,cap,ind+1,n,dp));
    //     return dp[ind][buy][cap] =  profit;                 
    // }
    
    int maxProfit(int p,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(p+1,0)));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=1;j++){
        //         dp[i][j][0] = 0;
        //     }
        // }
        // for(int i=0;i<=1;i++){
        //     for(int j=0;j<=2;j++){
        //         dp[0][i][j] = 0;
        //     }
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=p;k++){
                    if(j==1){
                        dp[i][j][k] = max((-prices[i] + dp[i+1][0][k]), 0 + dp[i+1][1][k]);
                    }
                    else{
                        dp[i][j][k] = max((prices[i] + dp[i+1][1][k-1]), 0 + dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][p];
    }
};
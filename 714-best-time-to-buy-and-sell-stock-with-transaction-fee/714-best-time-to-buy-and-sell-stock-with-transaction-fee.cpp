class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(3,0));
        // dp[n][0] = dp[n][1] = 0;
        for(int i=n-1;i>=0;i--){
          
           
            dp[i][1] = max((-prices[i] + dp[i+1][0]), 0 + dp[i+1][1]);

            dp[i][0] = max((prices[i]-fee +dp[i+1][1]), 0 + dp[i+1][0]);

        }
        // for(int i=0;i<n;i++){
        //     cout << dp[i][0] << " " << dp[i][1]  << endl;
        // }
        return dp[0][1];
    }
};
class Solution {
public:
    
    // int helper(int ind, vector<int>& count, int target){
    //     if(ind==0){
    //         if(count[0]==)
    //     }
    // }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        
        for(int T = 0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T] = T/coins[0];
            else dp[0][T] =1e9;
        }
        
        for(int i =1;i<n;i++){
            for(int T =0;T<=amount;T++){
                int notTaken = 0 +dp[i-1][T];
                int taken = 1e9;
                if(coins[i]<=T) taken = 1 + dp[i][T-coins[i]];
                
                dp[i][T] = min(taken, notTaken);
            }
            
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
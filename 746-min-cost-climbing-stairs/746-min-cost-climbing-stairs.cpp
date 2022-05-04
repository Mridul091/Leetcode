class Solution {
public:
    
    int helper(int n, vector<int> &cost, vector<int> &dp){
        if(n==0 || n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        int left = helper(n-1, cost,dp) + cost[n-1];
     
        int right = helper(n-2, cost,dp) + cost[n-2];
        
        return dp[n] = min(left, right);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return helper(n, cost,dp);
    }
};
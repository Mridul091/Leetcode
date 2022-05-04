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
        // vector<int> dp(n,0);
        int first = cost[0];
        int second = cost[1];
        int cur;
        for(int i=2;i<n;i++){
//             int left = dp[i-1] + cost[i];
//             int right = dp[i-2] + cost[i];
            
//             dp[i] = min(left, right);
            int cur = min(first, second) + cost[i];
            first = second;
            second = cur;
        }
        return min(second ,first);
    }
};
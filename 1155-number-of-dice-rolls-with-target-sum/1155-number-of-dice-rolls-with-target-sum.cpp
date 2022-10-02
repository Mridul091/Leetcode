class Solution {
    int mod = 1e9+7;
public:
    
    int helper(int n, int k, int target, vector<vector<int>>& dp){
        
        if(n==0){
            if(target==0) return 1;
            return 0;
        }
        if(target <=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int res = 0;
        for(int i =1;i<=k;i++){
            if(i<=target){
                res += helper(n-1,k, target-i, dp);
                res = res%mod;
            }
        }
         dp[n][target] = res;
        return dp[n][target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(32, vector<int> (1005,-1));
        return helper(n,k,target,dp);
    }
};
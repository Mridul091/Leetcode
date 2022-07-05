class Solution {
public:
    
//     int helper(int n, vector<int> &dp){
//         if(n<=2) return 1;
        
//         if(dp[n]!= -1) return dp[n];
        
//         return dp[n] = helper(n-1, dp) + helper(n-2, dp);
//     }
    
    int climbStairs(int n) {
        
        int prev2 = 1;
        int prev = 1;
        // dp[2] = 1;
        for(int i=2;i<=n;i++){
            int steps = prev2 + prev;
            prev2 = prev;
            prev = steps;
        }
        return  prev;
    }
};

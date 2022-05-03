class Solution {
public:
    
    int helper(int n, vector<int> &dp){
        if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    
    int fib(int n) {
        // recursive solution
//         if(n<=1)
//             return n;
        
//         return fib(n-1) + fib(n-2);
        // Memoization solution
        // vector<int> dp(n+1,-1);
        // int ans =  helper(n, dp);
        // return ans;
        
//         tabulation with space optimization
        
        int prev2 = 0;
        int prev = 1;
        if(n==0) return 0;
        for(int i= 2;i<=n;i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
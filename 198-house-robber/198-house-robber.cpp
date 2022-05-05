class Solution {
public:
    
//     int helper(int ind, vector<int> &nums, vector<int> &dp){
//         if(ind == 0) return nums[ind];
//         if(ind<0) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int left = nums[ind] + helper(ind-2, nums, dp);
//         int right = helper(ind-1, nums ,dp);
        
//         return dp[ind] = max(left, right);
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 0);
        // return helper(n-1, nums, dp);
        
        int prev1 = nums[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int left  = nums[i];
            if(i>1) left+= prev2;
            int right = prev1;
            int curr = max(left, right);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
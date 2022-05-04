class Solution {
public:
    
    int helper(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left = nums[ind] + helper(ind-2, nums, dp);
        cout << left << endl;
        int right = helper(ind-1, nums ,dp);
        
        return dp[ind] = max(left, right);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, nums, dp);
    }
};
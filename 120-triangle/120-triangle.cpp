class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp){
        if(i==nums.size()) return 0;
        // if(j>=nums[i].size()) return 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down = nums[i][j] + helper(i+1,j ,nums,dp);
        int right = nums[i][j] + helper(i+1,j+1,nums, dp);
        
        return dp[i][j] =  min(down, right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        
        vector<vector<int>> dp(h, vector<int>(h,-1));
        return helper(0,0,triangle, dp);
    }
};
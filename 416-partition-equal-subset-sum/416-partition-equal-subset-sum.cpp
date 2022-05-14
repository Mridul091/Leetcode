class Solution {
public:
    
    
    bool helper(int i, int k, vector<int>& ans, vector<vector<int>>& dp){
	if(k==0) return true;
	if(i==0) return ans[i]==k;
	
	if(dp[i][k]!=-1) return dp[i][k];
	
	bool nottaken = helper(i-1, k,ans, dp);
	
	bool taken = false;
	if(ans[i]<=k)
		taken = helper(i-1,k-ans[i], ans, dp);
	
	return dp[i][k] =  nottaken || taken;
	
}
    
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(auto it: nums)
            sum+=it;
        
        if(sum%2!=0) return false;
        
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, target, nums, dp);
    }
};
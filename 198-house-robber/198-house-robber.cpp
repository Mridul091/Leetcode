class Solution {
public:
    
    int helper(vector<int>& nums, int ind, vector<int>& dp){
        if(ind==0) return nums[0];
        if(ind==-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left = helper(nums, ind-1, dp);
        int right = helper(nums,ind-2, dp) + nums[ind];
        
        return dp[ind] =  max(left, right);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 0);
        int prev1= nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int left = prev1;
            int right = nums[i];
            if(i>1)
                right+= prev2;
            
            int curr_i = max(left, right);
            prev2 = prev1;
            prev1 = curr_i;
        }
        // for(int i=0;i<n;i++)
        //     cout << dp[i] << " ";
        return prev1;
    }
};
class Solution {
public:
    int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n==1) return nums[0];
        
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        
        return max(rob1(temp1),rob1(temp2));
    }
};
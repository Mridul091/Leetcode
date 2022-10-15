class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]>=dp[i])
                    dp[i] = 1 + dp[j];
            }
        }
        int ans =0;
        for(int i=0;i<n;i++)
            cout << dp[i] << " ";
        for(int i =0;i< n ;i++)
            ans = max(ans, dp[i]);
        
        return ans;
        // int n = nums.size();
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // int len = 1;
        // for(int i=1;i<n;i++){
        //     if(nums[i] > temp.back()){
        //         temp.push_back(nums[i]);
        //         len++;
        //     }
        //     else{
        //         int ind = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
        //         temp[ind] = nums[i];
        //     }
        // }
        // return len;
    }
};
class Solution {
public:
    
    // int helper(vector<int>& nums, int ind, int k){
    //     if(ind==nums.size()-1) return nums[ind];
    //     int maxi = INT_MIN;
    //     for(int i=1;i<=k;i++){
    //         int cnt =0;
    //         if(ind+i<nums.size())
    //             cnt= nums[ind] + helper(nums,ind+i,k);
    //         maxi = max(cnt, maxi);
    //     }
    //     return maxi;
    // }
    
    int maxResult(vector<int>& nums, int k) {
               int n = nums.size();
        vector<int> dp(n, INT_MIN);
        multiset<int> s({dp[0] = nums[0]});
        
        for(int i=1; i<n; i++) {
            if(i > k) s.erase(s.find(dp[i-k-1]));
            s.insert(dp[i] = *s.rbegin() + nums[i]);
        }
        return dp[n-1];
    }
};
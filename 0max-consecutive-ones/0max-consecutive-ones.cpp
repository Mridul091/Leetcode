class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxOne = 0;
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0;i<n;i++) {
            if(nums[i]==1){
                maxOne++;
                if(maxOne > ans){
                    ans = maxOne;
                }
            }
            else
                maxOne = 0;
        }
        return ans;
    }
};
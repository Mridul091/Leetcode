class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int l=0;
        int r=0;
        int sum = 0;
        int ans =0;
        while(r<n){
            while(s.find(nums[r])!=s.end()){
                sum -= nums[l];
                s.erase(nums[l++]);
            }
            
            sum += nums[r];
            s.insert(nums[r]);
            r++;
            ans = max(sum, ans);
        }
        return ans;
    }
};
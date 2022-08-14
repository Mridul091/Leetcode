class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long max = *max_element(nums.begin(), nums.end());
        if(max<0) return 1;
        unordered_set<int> mp;
        for(auto it: nums) mp.insert(it);
        // int first_pos= INT_MAX;
        // for(int i =0;i<nums.size();i++){
        //     if(nums[i]<0) continue;
        //     first_pos = min(first_pos, nums[i]);
        // }
        int ans;
        for(long long i=1;i<=max+1;i++){
            if(mp.find(i)==mp.end()){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
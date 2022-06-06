class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return {};
        sort(nums.begin(), nums.end());
        if(nums[0]>0)
            return {};
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        
        for(int i =0;i<n-2;i++){
            for(int j =i+1;j<n-1;j++){
                int temp = nums[i] + nums[j];
                if(mp.find(-temp)!=mp.end() && mp.find(-temp)->second > j){
                    ans.push_back({nums[i], nums[j], -temp});
                }
                j = mp.find(nums[j])->second;
            }
            i = mp.find(nums[i])->second;
        }
        return ans;
    }
};
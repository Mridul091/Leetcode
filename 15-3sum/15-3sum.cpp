class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
//         if(n<3)
//             return {};
        sort(nums.begin(), nums.end());
//         if(nums[0]>0)
//             return {};
//         unordered_map<int, int> mp;
//         vector<vector<int>> ans;
//         for(int i=0;i<n;i++){
//             mp[nums[i]] = i;
//         }
        
//         for(int i =0;i<n-2;i++){
//             for(int j =i+1;j<n-1;j++){
//                 int temp = nums[i] + nums[j];
//                 if(mp.find(-temp)!=mp.end() && mp.find(-temp)->second > j){
//                     ans.push_back({nums[i], nums[j], -temp});
//                 }
//                 j = mp.find(nums[j])->second;
//             }
//             i = mp.find(nums[i])->second;
//         }
//         return ans;
        
        vector<vector<int>> res;
        for(int i = 0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int lo = i+1, hi = n-1, target = -nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo < hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo < hi && nums[hi]==nums[hi-1]) hi--;
                        lo++, hi--;
                    }
                    else if(nums[lo] + nums[hi] < target) lo++;
                    else hi--;
                }
            }
        }
        return res;
    }
};
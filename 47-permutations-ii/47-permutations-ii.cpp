class Solution {
public:
    
    void perm(vector<int> &nums, int i, vector<vector<int>> &ans){
        // basecase
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for(int j=i;j<nums.size();j++){
            if(seen.find(nums[j]) != seen.end()) continue;
                seen.insert(nums[j]);
                swap(nums[i],nums[j]);
                perm(nums,i+1,ans);
                swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,0,ans);
        return ans;
    }
};

// class Solution {
    

//     void permute(vector<int> &nums, int index, vector<vector<int>>& ans) {
//         if (index == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         unordered_set<int> s;
//         for (int i = index; i < nums.size(); i++) {
//             if (s.find(nums[i]) != s.end())    continue;
//             s.insert(nums[i]);
//             swap(nums[index], nums[i]);
//             permute(nums, index + 1, ans);
//             swap(nums[index], nums[i]);
//         }
//     }

// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         permute(nums, 0, ans);
//         return ans;
//     }
// };
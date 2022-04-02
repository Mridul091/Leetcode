class Solution {
public:
    //1s approach
void helper(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, bool prev, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
    
        if(target<0) return;
        if(ind>=nums.size()) return;
        else{
            // to ignore the value
          
            helper(ind+1, nums, temp, ans, true, target);
            if(ind>0 && nums[ind]==nums[ind-1] && (prev))
            return;
            
            // to take the value in the consideration
            temp.push_back(nums[ind]);
            helper(ind+1,nums,temp,ans,false,(target-nums[ind]));
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, nums, temp, ans, false, target);
        return ans;
    }
};
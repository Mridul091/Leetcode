class Solution {
public:
    
    void helper(int ind, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, bool prev){
        if(ind==nums.size())
            ans.push_back(temp);
        
        else{
            // to ignore the value
          
            helper(ind+1, nums, temp, ans, true);
            if(ind>0 && nums[ind]==nums[ind-1] && (prev))
            return;
            
            // to take the value in the consideration
            temp.push_back(nums[ind]);
            helper(ind+1,nums,temp,ans,false);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, nums, temp, ans, false);
        return ans;
    }
};
class Solution {
public:
    void helper(int ind, vector<int> &input, int target, vector<vector<int>>&ans, vector<int> &output){
        if(target==0){
            ans.push_back(output);
            return;
        }
        if(target<0)
            return;
        if(ind==input.size())
            return;
        
        helper(ind+1, input, target, ans, output);
        output.push_back(input[ind]);
        helper(ind, input, target-input[ind], ans, output);
        
        output.pop_back();
    }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
 
        helper(0, candidates, target, ans, temp);
        
        return ans;
    }
};
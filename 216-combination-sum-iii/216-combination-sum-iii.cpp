class Solution {
public:
    
    void helper(int dig, int sum, int k, int n,vector<vector<int>>& ans, vector<int>& temp){
        
        if(k==0 && sum== n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=dig;i<=9;i++){
            temp.push_back(i);
            helper(i+1, sum+i,k-1,n, ans, temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> temp;
        
        helper(1,0,k,n,ans,temp);
        
        return ans;
    }
};
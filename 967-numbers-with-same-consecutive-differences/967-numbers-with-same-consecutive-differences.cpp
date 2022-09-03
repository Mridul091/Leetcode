class Solution {
public:
    
    void helper(int n, int k , int sum, int next, vector<int>& ans){
        if(n==0){
            ans.push_back(sum);
            return;
        }
        
        for(int i = 0;i<=9;i++){
            if(k==abs(i-next))
                helper(n-1, k, sum*10+i, i, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1;i<=9;i++){
            helper(n-1,k,i,i, ans);
        }
        return ans;
    }
};
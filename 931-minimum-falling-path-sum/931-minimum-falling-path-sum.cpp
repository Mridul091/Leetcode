class Solution {
public:
    
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        
        if(j>=matrix.size()|| j<0) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j] + helper(i-1,j, matrix, dp);
        int ld = matrix[i][j] + helper(i-1,j-1, matrix, dp);
        int rd = matrix[i][j] + helper(i-1, j+1, matrix, dp);
        
        return dp[i][j] =  min(up, min(ld,rd));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e9;
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        for(int j=0;j<n;j++)
            mini =   min(mini, helper(n-1,j, matrix, dp));
        
        return mini;
    }
    
};
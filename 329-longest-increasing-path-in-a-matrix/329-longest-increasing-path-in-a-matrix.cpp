class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isvalid(int i, int n, int j ,int m){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        return false;
    }
    
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int n= matrix.size();
        int m = matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int temp = 1;
        for(int k=0;k<4;k++){
            int new_i = i+dx[k];
            int new_j = j+dy[k];
            
            if(isvalid(new_i, n, new_j, m) && matrix[new_i][new_j] > matrix[i][j]){
                temp = max(temp, 1 + helper(matrix, new_i, new_j, dp));
            }
        }
        return dp[i][j] = temp;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int len = 1;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                len = max(len, helper(matrix, i ,j, dp));
            }
        }
        return len;
    }
};
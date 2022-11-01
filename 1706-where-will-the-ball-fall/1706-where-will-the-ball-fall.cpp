class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        for(int i = 0;i<m;i++) dp[n][i] = i;
        
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    bool flag = (j + 1 == m)? false : (grid[i][j + 1] == 1);
                    if (flag) dp[i][j] = dp[i + 1][j + 1];
                }
                else if(grid[i][j]==-1){
                    bool flag = (j - 1 < 0)? false : (grid[i][j - 1] == -1);
                    if (flag) dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        return dp[0];
    }
};
class Solution {
public:
    long long mod = 1e9 + 7;
    int helper(int m, int n, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if((i<0 || j<0 || i>=m || j>=n))
            return 1;
        if (k==0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int left = helper(m,n,i,j-1,k-1,dp);
        int right = helper(m,n,i,j+1,k-1,dp);
        int up = helper(m,n,i-1,j,k-1,dp);
        int down = helper(m,n,i+1,j,k-1,dp);
        return dp[i][j][k] = ((up%mod) + (down%mod) + (right%mod) + (left%mod))%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int cnt = 0;
            vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
            cnt += helper(m,n,startRow,startColumn, maxMove, dp);
 
        return cnt;
    }
};

// ((up % mod) + (down % mod) + (left % mod) + (right % mod)) % mod
class Solution {
private:
    
    int helper(int index, vector<int> &jobDifficulty, int d, vector<vector<int>>& dp){
        int n = jobDifficulty.size();
        if(d == 1){
            int maxi = 0;
            while(index < n) maxi = max(maxi, jobDifficulty[index++]);
            return maxi;
        }
        if(dp[index][d] != -1) return dp[index][d];
        int res = INT_MAX, maxi = 0;
        for(int i = index; i < n - d + 1; ++i){
            maxi = max(maxi, jobDifficulty[i]);
            res = min(res, maxi + helper(i + 1, jobDifficulty, d - 1,dp));
        }
        return dp[index][d] = res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d+1, -1));
        return helper(0, jobDifficulty, d, dp);
    }
};
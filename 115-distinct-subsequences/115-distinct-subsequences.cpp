class Solution {
public:
    
    int helper(string &s, string &t, int i , int j, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = helper(s,t,i-1,j-1, dp) + helper(s,t,i-1,j, dp);
        else
            return dp[i][j] = helper(s,t,i-1,j, dp);
    }
    
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        vector<vector<int>> dp(s1, vector<int>(s2,-1));
        return helper(s, t, s1-1, s2-1, dp);
    }
};
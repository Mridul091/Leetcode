class Solution {
public:
    
    bool helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& dp){
        if(i<0 && j <0 && k <0) return true;
        if( i>= 0 && j>= 0 && dp[i][j]!=-1) return dp[i][j];
        if(i>=0 && j>=0 && s1[i]==s3[k] && s2[j]==s3[k]) return dp[i][j] = helper(s1,s2,s3, i-1,j,k-1,dp) || helper(s1,s2,s3, i, j-1, k-1,dp);
        else if(i>=0 && s1[i]==s3[k]) return  helper(s1,s2,s3, i-1,j,k-1, dp);
        else if(j>=0 && s2[j]==s3[k]) return  helper(s1,s2,s3, i,j-1,k-1, dp);
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        if(n3 != n1 + n2) return false;
        return helper(s1,s2,s3, n1-1, n2-1,n3-1, dp);
    }
};
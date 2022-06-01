class Solution {
public:
    
    // int helper(string &s, string &t, int i , int j, vector<vector<int>> &dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]) return dp[i][j] = helper(s,t,i-1,j-1, dp) + helper(s,t,i-1,j, dp);
    //     else
    //         return dp[i][j] = helper(s,t,i-1,j, dp);
    // }
    
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        vector<double> prev(s2+1, 0), curr(s2+1, 0); 
        
        prev[0] = curr[0] = 1;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(s[i-1]==t[j-1])
                    curr[j] = prev[j-1]  + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[s2];
    }
};
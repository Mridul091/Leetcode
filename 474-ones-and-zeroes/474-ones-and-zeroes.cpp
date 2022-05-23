class Solution {
public:
    
//     int helper(int ind, int nzero, int nones, vector<pair<int, int>>& count, vector<vector<vector<int>>> &dp ){
//         int n = count.size();
        
//         if(ind == n || (nzero==0 && nones==0)) return 0;
//         if(dp[ind][nzero][nones]!=-1) return dp[ind][nzero][nones];
//         if(count[ind].first > nzero || count[ind].second > nones)
//             return helper(ind+1, nzero, nones, count, dp);
        
//         int include = 1+helper(ind+1, nzero - count[ind].first, nones-count[ind].second, count, dp);
//         int exclude = helper(ind+1, nzero, nones, count, dp);
        
//         return dp[ind][nzero][nones] =  max(include, exclude);
//     }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<pair<int, int>> count;
//         int s = strs.size();
//         // vector<vector<vector<int>>> dp(s+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
//         for(auto i : strs){
//             int ones=0, zeros = 0;
//             for(auto it: i){
//                 (it == '1') ? ones ++ : zeros++;
            
//             }
//             count.push_back({zeros, ones});
//         }
        // cout << count.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto &s: strs){
            int x = count(s.begin(), s.end(), '1');
            int y = s.size()-x;
            for(int i=m;i>=y;i--){
                for(int j=n;j>=x;j--){
                    dp[i][j] = max(dp[i][j],1+ dp[i-y][j-x]);
                }
            }
        }

        return dp[m][n];
    }
};
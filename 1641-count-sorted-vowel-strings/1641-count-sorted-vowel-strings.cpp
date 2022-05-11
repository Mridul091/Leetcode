class Solution {
public:
    
//     void helper(int n, vector<vector<char>>& ans, vector<char>& temp, vector<char>& vowel, int k){
        
//         if(temp.size()==n){
//             ans.push_back(temp);
//             return;
//         }
        
//         for(int i=k;i<vowel.size();i++){
            
//             temp.push_back(vowel[i]);
//             helper(n, ans, temp, vowel, i);
//             temp.pop_back();  
//         }
//         return;
//     }
    
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<5;j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[4];
    }
};
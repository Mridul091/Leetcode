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
        return (n+4)*(n+3)*(n+2)*(n+1) / 24;
    }
};
class Solution {
public:
    
    void helper(int n, vector<vector<char>>& ans, vector<char>& temp, vector<char>& vowel, int k){
        
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=k;i<vowel.size();i++){
            
            temp.push_back(vowel[i]);
            helper(n, ans, temp, vowel, i);
            temp.pop_back();  
        }
        return;
    }
    
    int countVowelStrings(int n) {
        vector<vector<char>> ans;
        vector<char> temp;
        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        helper(n, ans, temp, vowel,0);
        return ans.size();
    }
};
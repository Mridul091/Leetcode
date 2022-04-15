class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0,s,res,path);
    return res;
    }
    
    void helper(int start, string s, vector<vector<string>> &res, vector<string> &path){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i= start; i<s.size();i++){
            if(isPalindrome(s, start, i)){
                path.push_back(s.substr(start, i-start+1));
                helper(i+1, s, res, path);
                path.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string s, int l, int r){
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
};
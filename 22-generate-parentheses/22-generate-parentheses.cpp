class Solution {
public:
    
//     bool isvalid(string& s){
//         int diff =0;
//         for(auto it: s){
//             if(it=='(')
//                 diff= diff+1;
//             else 
//                 diff = diff-1;
//             if(diff<0) return false;
//         }
        
//         return !diff;
//     }
    
//     void helper(string s, int n, vector<string>& ans){
//         if(s.size()==n){
//             if(isvalid(s))
//                 ans.push_back(s);
//             return;
//         }
        
//         helper(s+'(', n, ans);
//         helper(s+')', n, ans);
        
//     }
    
    void helper(int s, int e, int n, string temp, vector<string>& ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        
        if(s<n) helper(s+1, e, n, temp+'(', ans);
        if(s>e) helper(s, e+1, n, temp+')', ans);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0,0,n,"", ans);
        return ans;
    }
};
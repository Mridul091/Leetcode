// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    void helper(int ind , string s, vector<vector<string>>& res, vector<string>& path){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                helper(i+1, s, res, path);
                path.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> res;
        vector<string> path;
        helper(0, S, res, path);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
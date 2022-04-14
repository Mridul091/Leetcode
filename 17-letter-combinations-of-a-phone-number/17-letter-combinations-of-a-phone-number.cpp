class Solution {
public:
string getString(int n){
    string s;
    if(n == 2) 
        s="abc";
    else if(n == 3) 
        s= "def";
    else if(n == 4) 
        s= "ghi";
    else if(n == 5) 
        s= "jkl";
    else if(n == 6) 
        s= "mno";
    else if(n == 7) 
        s= "pqrs";
    else if(n == 8) 
        s= "tuv";
    else if(n == 9) 
        s= "wxyz";
    
return s;
}
    
 void helper(int n, string s,vector<string> &ans){
        if(n==0){
            ans.push_back(s);
        }
        
        int r = n%10;
        string small = getString(r);
         n=n/10;
        for(int i=0;i<small.size();i++){
            helper(n,small[i]+s,ans);
            cout << small[i] << endl;
        }   
    
    }
    vector<string> letterCombinations(string digits) {
        string output = "";
         vector<string> ans;
        int k = digits.size();
        if(k==0){
            return ans;
        }
        int n = stoi(digits);
       
        helper(n,output,ans);
        return ans;
    }
};
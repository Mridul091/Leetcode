class Solution {
public:
    bool validPalindrome(string s) {
        int n =  s.size();
        int i = 0;
        int j = n-1;
        
        while(i<=j){
            if(s[i]!=s[j])
                return helper(s,i+1,j) || helper(s,i,j-1);
            i++;
            j--;
        }
        return true;
    }
    
    bool helper(string s, int st, int e){
        int i = st;
        int j = e;
        
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
};
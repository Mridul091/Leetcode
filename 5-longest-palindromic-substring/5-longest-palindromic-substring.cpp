class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len= 0;
        string ans = "";
        int start;
        int l, r;
        for(int i=0;i<n;i++){
            l = i-1;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1> len){
                    len = r-l+1;
                    start = l;
                } 
                l--;
                r++;
            }
            l = i, r=i+1;
             while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1> len){
                    len = r-l+1;
                    start = l;
                } 
                l--;
                r++;
            }
        }
        
        if(len==0){
            ans += s[0];
            return ans;
        }
        for(int i=start;i<start+len;i++){
            ans += s[i];
        }
        return ans;
    }
};

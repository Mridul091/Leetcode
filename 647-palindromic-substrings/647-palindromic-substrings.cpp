class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt= 0;
        
        for(int i=0;i<n;i++){
            int l = i-1;
            int r = i+1;
            
            cnt++;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
            l = i, r=i+1;
             while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};
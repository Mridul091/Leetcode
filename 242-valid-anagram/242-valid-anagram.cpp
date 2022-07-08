class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        if(n1!=n2) return false;
        int cnt[256] = {0};
        for(int i=0;i<n1;i++){
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        
        for(int i=0;i<256;i++){
            if(cnt[i]!=0) return false;
        }
        return true;
    }
};
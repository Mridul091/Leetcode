class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> cnt(26,0);
        for(int i=0;i<s.length();i++){
            cnt[s.at(i)-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(cnt[s.at(i)-'a']==1) return i;
        }
        return -1;
    }
};
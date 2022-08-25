class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // int n = ransomNote.size();
        // int m = magazine.size();
        // if(n < m) return false;
        
        int mp[26] = {0};
        for(char x: ransomNote){
            mp[x-'a']++;
        }
        for(char x: magazine){
            mp[x-'a']--;
        }
        
        for(int i =0;i<26;i++){
            if(mp[i]>0) return false;
        }
        return true;
    }
};
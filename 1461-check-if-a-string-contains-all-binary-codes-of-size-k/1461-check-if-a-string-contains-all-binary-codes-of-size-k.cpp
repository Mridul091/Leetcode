class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string, int> mp;
        for(int i=0;i+k<=s.size();i++){
            mp[s.substr(i,k)]++;
        }
        return mp.size()==pow(2,k);
    }
};
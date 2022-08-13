class Solution {
public:
    
    bool helper(string s, unordered_map<string, int> mp, int len){
        for(int i =0;i<s.size();i+= len){
            string tmp = s.substr(i,len);
                if(mp.find(tmp)!=mp.end()){
                    if(mp[tmp]<=0) return false;
                    mp[tmp]--;
                }
                else return false;
            
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int subs_size = words[0].size();
        int full_size = words.size();
        int sz = subs_size*full_size;
        vector<int> res;
        int n = s.size();
        unordered_map<string, int> mp;
        for(auto str: words)
            mp[str]++;
        
        int i =0;
        while(i+sz <= n){
            if(helper(s.substr(i,sz), mp, subs_size)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};
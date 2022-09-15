class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        for(int x: changed) mp[x]++;
        
        vector<int> ans;
        for(auto x: mp){
            int cnt = x.first;
            if(mp[cnt]==0) continue;
            while(mp[cnt] > 0){
                ans.push_back(cnt);
                mp[cnt]--;
                mp[cnt*2]--;
            }
            if(mp[cnt] <0) return{};
        }
        return ans;
    }
};
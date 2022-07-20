class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for(auto x: rs){
            mp[x[0]].push_back(x[1]);
        }
        ans = (n-mp.size())*2;
        // cout << n << " " << mp.size() << endl;
        
        for(auto r: mp){
            bool flag = 0;
            vector<bool> vis(11,0);
            for(auto x: r.second){
                vis[x] = 1;
            }
            
            if(!vis[2] && !vis[3] && !vis[4] && !vis[5]){
                ans++;
                flag = 1;
            }
            if(!vis[6] && !vis[7] && !vis[8] && !vis[9]){
                ans++;
                flag = 1;
            }
            if(!flag){
                if(!vis[4] && !vis[5] && !vis[6] && !vis[7])
                    ans++;
            }
        }
        return ans;
    }
};
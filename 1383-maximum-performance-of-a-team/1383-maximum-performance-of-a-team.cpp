class Solution {
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0;i<n;i++){
            res.push_back({efficiency[i], speed[i]});
        }
        long ans = 0, s = 0;
        sort(res.rbegin(),res.rend());
        
        for(auto v: res){
            int curr_eff = v.first;
            int curr_speed = v.second;
            
            if(pq.size() == k){
                s -= pq.top();
                pq.pop();
            }
            
            pq.push(curr_speed);
            s += curr_speed;
            
            ans = max(ans, s*curr_eff);
        }
        
        
        return ans % mod;
    }
};
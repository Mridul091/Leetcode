#define pii pair<int, pair<int,int>>
class Solution {
public:
    
    const int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
    
    int minimumEffortPath(vector<vector<int>>& hts) {
        int n = hts.size(); 
        int m = hts[0].size();
        
        priority_queue <pii, vector<pii> ,greater<pii>> pq;
        vector<vector<int>> dis(n,vector<int>(m, INT_MAX));
        
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            pii cur = pq.top(); pq.pop();
            int d = cur.first, r= cur.second.first, c = cur.second.second;
            if(r==n-1 && c==m-1) return d;
            for(int i =0;i<4;i++){
                int nx = r+dx[i], ny= c+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                int nd = max(d, abs(hts[nx][ny] - hts[r][c]));
                if (nd < dis[nx][ny]) {
                    dis[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        return 0;
    }
};
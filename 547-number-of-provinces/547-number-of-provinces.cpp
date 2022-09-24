class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int i, vector<int>& vis){
        vis[i] = 1;
        for(int j = 0;j<graph.size();j++){
            if( graph[i][j] == 1 && !vis[j]) dfs(graph, j, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        
        int cnt = 0;
        for(int i  = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected, i,vis);
            }
        }
        return cnt;
    }
};
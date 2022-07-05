class Solution {

public: 
//     bool bipartite(int node, vector<vector<int>> adj,vector<int> &color ){
//     if(color[node]==-1) color[node] = 1;

//     for(auto it : adj[node]){
//         if(color[it]==-1){
//             color[it] = 1- color[node];
//             if(!bipartite(it, adj, color)) return false;
//         }else if(color[it]==color[node]) return false;
//     }
//     return true;
// }
public:
    
    bool bipartite(int src, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if(color[node]==color[it])return false;
             }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
    int v = graph.size();
    vector<int>color(v, -1);
 
    for(int i = 0;i<v;i++){
        if(color[i] == -1){
            if(!bipartite(i, graph, color)){
                return false;
            }
        }
    }
    return true;

    }
};
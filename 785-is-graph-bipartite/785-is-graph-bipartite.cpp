class Solution {

public: 
    bool bipartite(int node, vector<vector<int>> adj,vector<int> &color ){
    if(color[node]==-1) color[node] = 1;

    for(auto it : adj[node]){
        if(color[it]==-1){
            color[it] = 1- color[node];
            if(!bipartite(it, adj, color)) return false;
        }else if(color[it]==color[node]) return false;
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size()+1);
        
        for(int i=0;i<graph.size();i++)
        {   for(int k=0;k<graph[i].size();k++)
             adj[i].push_back(graph[i][k]);  
        }
        
    vector<int>color(graph.size()+1, -1);
 
    for(int i = 0;i<graph.size();i++){
        if(color[i] == -1){
            if(!bipartite(i, adj, color)){
                return false;
            }
        }
    }
    return true;

    }
};
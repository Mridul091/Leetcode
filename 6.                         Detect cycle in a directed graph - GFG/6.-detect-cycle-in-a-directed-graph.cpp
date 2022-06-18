// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool>& rec, int src){
        vis[src] = true;
        rec[src] = true;
        for(int& u: adj[src]){
            if(vis[u]==false && dfs(adj, vis, rec, u))
                return true;
            else if(rec[u])
                return true;
        }
        rec[src] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(dfs(adj, vis, rec, i))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
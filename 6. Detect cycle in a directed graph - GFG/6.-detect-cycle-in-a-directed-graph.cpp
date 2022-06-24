// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    // bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool>& rec, int src){
    //     vis[src] = true;
    //     rec[src] = true;
    //     for(int& u: adj[src]){
    //         if(vis[u]==false && dfs(adj, vis, rec, u))
    //             return true;
    //         else if(rec[u])
    //             return true;
    //     }
    //     rec[src] = false;
    //     return false;
    // }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // vector<bool> vis(V,false);
        // vector<bool> rec(V,false);
        
        // for(int i=0;i<V;i++){
        //     if(vis[i]==false){
        //         if(dfs(adj, vis, rec, i))
        //             return true;
        //     }
        // }
        // return false;
        vector<int> indegree(V,0);
        queue<int> q;
    //     for(int i=0;i<V;i++)
    //         for(auto a: adj[i]){
    //             indegree[a]++;
    //         }
    // }
    //   for(int i=0;i<V;i++){
    //      for(auto x:adj[i]){
    //          indegree[x]++;
    //      }
    //  }
    //     queue<int>q;
    //     for(int i=0;i<V;i++){
    //         if(indegree[i]==0)
    //             q.push(i);
    //     }
         for(int i=0;i<V;i++)
     {
         for(auto j:adj[i])
             indegree[j]++;
     }
     
     for(int i=0;i<V;i++)
     {
         if(indegree[i]==0)
         q.push(i);
     }
        int count =0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            // for(auto a: adj[front]){
            //     indegree[a]--;
            //     if(indegree[a]==0);
            //         q.push(a);
            // }
                    for(auto it:adj[front])
            {
                indegree[it]--;
                
                if(indegree[it]==0)
                q.push(it);
            }
        }
    //       while(!q.empty())
    //  {
    //      int node=q.front();
    //      q.pop();
    //      count++;  // extra variable to check whether number of nodes in queue is equal to given number of nodes, if yes then it indicates that it will have topological sort then we conclude that this graph doesn't have cycle
         
    //      for(auto it:adj[node])
    //         {
    //             indegree[it]--;
                
    //             if(indegree[it]==0)
    //             q.push(it);
    //         }
    //  }
        return !(count == V);
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
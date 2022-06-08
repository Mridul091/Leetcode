// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
        //         queue<int> q;
        //         q.push(i);
        //         visited[i] = true;
        //         while(!q.empty()){
        //             int front = q.front();
        //             q.pop();
        //             ans.push_back(front);
        //             for(auto it: adj[front]){
        //                 if(!visited[it]){
        //                     q.push(it);
        //                     visited[it] =true;
        //                 }
        //             }
                    
        //         }
        //     }
        // }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto it: adj[front]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        // for(int i=0; i<n;i++){
        //     if(!visited[start]){
                queue<int> q;
                q.push(start);
                visited[start] = true;
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    
                    for(auto a : graph[front]){
                        if(!visited[a]){
                            q.push(a);
                            visited[a] = true;
                        }
                    }
                }
        //     }
        // }
        
        return visited[end];
    }
};
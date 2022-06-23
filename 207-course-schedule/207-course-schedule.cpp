class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &a :prerequisites){
            adj[a[0]].push_back(a[1]);
            indegree[a[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int a: adj[front]){
                indegree[a]--;
                if(indegree[a]==0)
                    q.push(a);
            }
            numCourses--;
        }
        return numCourses==0;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        
        vector<vector<int>> dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            if(r==n-1 && c==n-1) return grid[r][c];
            
            for(auto moves: dir){
                int nr = r + moves[0];
                int nc = c + moves[1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    q.push(make_pair(nr,nc));
                    grid[nr][nc] = grid[r][c] + 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};
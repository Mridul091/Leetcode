class Solution {
private:
     vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    
    
    void bfs(vector<vector<char>> &grid, int n, int m ,int i, int j){
        queue<int> q;
        // 2d->1d= R* #col + C
        // 1d->2d= R = index/#col, C = index%#col;
        
        q.push(i*m+j);
        grid[i][j] = '0';
        while(!q.empty()){
            int ind = q.front();
            int row = ind/m;
            int col = ind%m;
            q.pop();
            for(vector<int>& d: dirs){
                int x = row + d[0];
                int y = col + d[1];
                if(x>=0 && y >=0 && x<n && y <m && grid[x][y]=='1'){
                    q.push(x*m+y);
                    grid[x][y] = '0';
                }
            }
        }
    
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    island++;
                    bfs(grid, n, m, i, j);
                } 
            }
        }
        return island;
    }
};
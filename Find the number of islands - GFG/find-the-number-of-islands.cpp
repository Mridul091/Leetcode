// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
   vector<vector<int>> dirs = {{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
  public:
//   int bfs(vector<vector<char>>& edges, vector<bool>& visited, int n){
//     int cnt =0;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             queue<char> q;
//             q.push(i);
//             visited[i] = true;
//             while(!q.empty()){
//                 int front = q.front();
//                 q.pop();
//                 for(int j =0;j<n;j++){
//                     if(edges[front][j] && !visited[j]){
//                         q.push(j);
//                         visited[j] = true;
//                     }
//                 }
//             }
//              cnt++;
//         }
//         // ans.push_back(temp);
       
//     }
//     return cnt;
// }
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        queue<int> q;
        q.push(i*m+j);
        grid[i][j] ='0';
        while(!q.empty()){
            int ind = q.front();
            int row = ind/m;
            int col = ind%m;
            q.pop();
            for(vector<int>& d: dirs){
                int r = row + d[0];
                int c = col + d[1];
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c]=='1'){
                    q.push(r*m+c);
                    grid[r][c] = '0';
                }
            }
        }
    }
    //     void bfs(vector<vector<char>> &grid, int n, int m ,int i, int j){
    //     queue<int> q;
    //     // 2d->1d= R* #col + C
    //     // 1d->2d= R = index/#col, C = index%#col;
        
    //     q.push(i*m+j);
    //     grid[i][j] = '0';
    //     while(!q.empty()){
    //         int ind = q.front();
    //         int row = ind/m;
    //         int col = ind%m;
    //         q.pop();
    //         for(vector<int>& d: dirs){
    //             int x = row + d[0];
    //             int y = col + d[1];
    //             if(x>=0 && y >=0 && x<n && y <m && grid[x][y]=='1'){
    //                 q.push(x*m+y);
    //                 grid[x][y] = '0';
    //             }
    //         }
    //     }
    // }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int island =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                     island++;
                    bfs(grid,i,j,n,m);
                   
                }
            }
        }
        
        return island;
        //         int n = grid.size();
        // int m = grid[0].size();
        // int island = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]=='1'){
        //             island++;
        //             bfs(grid, n, m, i, j);
        //         } 
        //     }
        // }
        // return island;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
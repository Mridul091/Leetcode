class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int newval = ((i*n+j)+k)% (m*n);
                int newr = newval/n;
                int newc = newval%n;
                ans[newr][newc] = grid[i][j];
            }
        }
        return ans;
    }
};
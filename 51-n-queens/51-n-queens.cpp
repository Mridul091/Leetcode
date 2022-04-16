class Solution {
public:
    
    void helper(int col,vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &upper_left,             vector<int> &left, vector<int> &lower_left){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n;row++){
            if(lower_left[row + col]==0 && left[row]==0 && upper_left[n-1 + col - row]==0  ){
                board[row][col]='Q';
                lower_left[row + col]=1;
                left[row] = 1;
                upper_left[n-1 + col - row]=1;
                helper(col+1, ans, board, n, upper_left, left, lower_left);
                board[row][col]='.';
                lower_left[row + col]=0;
                left[row] = 0;
                upper_left[n-1 + col - row]=0;
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++) board[i] = s;
        vector<int> upper_left(2*n-1,0);
        vector<int> left(n,0);
        vector<int> lower_left(2*n-1, 0);
        helper(0, ans, board, n, upper_left, left, lower_left);
        return ans;
    }
};
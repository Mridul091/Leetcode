class Solution {
public:
    
    
    bool isSafe(int row, int col, int n, vector<string> &board){
        int x = row;
        int y = col;
        
        while(row>=0 && col >=0){
            if(board[row--][col--] == 'Q') return false;
        }
        
        row = x;
        col = y;
        
        while(col>=0){
            if(board[row][col--] =='Q') return false;
        }
        
        row = x;
        col = y;
        while(row<n && col>=0)
            if(board[row++][col--]=='Q') return false;
        
        
        return true;
    }
    
    int helper(int col, vector<string> &board, vector<vector<string>> &ans, int n, int &cnt){
        
        //base case
        if(col == n){
            ans.push_back(board);
            cnt++;
        }
        
        for(int row =0;row<n;row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                helper(col+1, board, ans, n, cnt);
                board[row][col] = '.';
            }
        }
        
        return cnt;
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0;i<n;i++)
            board[i] = s;
        int cnt = 0;
        int res = helper(0, board, ans, n, cnt);
        return res;
    }
};
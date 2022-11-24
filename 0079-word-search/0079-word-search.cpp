class Solution {
public:
    
    bool helper(vector<vector<char>> &board, string &word, int i, int j, int idx ){
        
        if(idx== word.size())
            return true;
        
        // check for out of bound conditions
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] != word[idx]) return false;
        board[i][j] = '0';
        
        bool res = helper(board, word, i+1,j,idx+1) ||
             helper(board, word, i-1,j,idx+1) || 
             helper(board, word, i,j+1,idx+1) ||
             helper(board, word, i,j-1,idx+1);
        
        board[i][j] = word[idx];
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] && helper(board,word, i,j,0))
                    return true;  
            }
        }
        return false;
    }
};
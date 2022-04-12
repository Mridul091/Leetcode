class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        vector<int> ans;
       
        int m = board.size();
        int n = board[0].size();
        
         for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                int count_live = 0;
                    if(i+1<m && j>=0 && board[i+1][j]==1)
                        count_live++;
                    if(i-1>=0 && j>=0 && board[i-1][j]==1)
                        count_live++;
                    if(j+1<n && i>=0 && board[i][j+1]==1)
                        count_live++;
                    if( j-1>=0 && i>=0 && board[i][j-1]==1)
                        count_live++;
                    if(i+1<m && j-1>=0 && board[i+1][j-1]==1) 
                        count_live++;
                    if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1)
                        count_live++;
                    if(i-1>=0 && j+1<n && board[i-1][j+1]==1)
                        count_live++;
                    if(i+1<m && j+1<n && board[i+1][j+1]==1)
                        count_live++;
                
                
            cout << count_live << " ";
                  
				if(!board[i][j]){
					if(count_live == 3)
						temp[i][j] = 1;
					else
						temp[i][j] = 0;

				}
                else{
					if((count_live<2) || (count_live>3))
						temp[i][j] = 0;
					else
						temp[i][j] = 1;
				}           
                
            }
         
        }
        board = temp;

    }
};
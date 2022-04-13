class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int start_col=0,start_row=0, end_col=n-1, end_row=n-1;
        int k=1;
        while(end_col>=start_col && end_row>=start_row){
            for(int i=start_col;i<=end_col;i++){
                ans[start_row][i] = k++;
            }
                
        start_row++;
            
            for(int i=start_row;i<=end_row;i++)
                ans[i][end_col] = k++;
                    
        end_col--;
            
        if(end_col>=start_col && end_row>=start_row){
        
            for(int i=end_col;i>=start_col;i--)
                ans[end_row][i] =k++;
                
        end_row--;

            for(int i=end_row;i>=start_row;i--)
                ans[i][start_col] = k++;
                
        start_col++;
        }
        }
            return ans;
    }
};
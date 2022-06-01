class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
//         vector<vector<int>> dup(n, vector<int>(m,0));
//         //taking a m*n matrix and storing the value of the given matrix in dupliucate
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++)
//                 dup[i][j] = matrix[i][j];
//         }
        
//         //taversing through the duplicate matrix and making required changes in the given matrix 2d vector
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(dup[i][j]==0){
//                     int xl = i;
//                     int xu = i;
//                     int yl = j;
//                     int yr = j;
//                     while(xu>=0){
//                         matrix[xu][j] = 0;
//                         xu--;
//                     }
//                     while(yl>=0){
//                         matrix[i][yl] = 0;
//                         yl--;
//                     }
//                     while(xl<n){
//                         matrix[xl][j] = 0;
//                         xl++;
//                     }
//                     while(yr<m){
//                         matrix[i][yr] = 0;
//                         yr++;
//                     }
//                 }
//             }
//         }
        // 2. Better Approach
        vector<int> row(n,-1);
        vector<int> col(m,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==0 || col[j]==0)
                    matrix[i][j] = 0;
            }
        }
    }
};
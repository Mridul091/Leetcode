class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> mt(n, vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && mt[i][j]==0 && mt[j][i]==0){
                    swap(matrix[i][j], matrix[j][i]);
                    mt[i][j] = 1;
                    mt[j][i] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
                // cout << matrix[i][j] << " ";
        }
    }
};
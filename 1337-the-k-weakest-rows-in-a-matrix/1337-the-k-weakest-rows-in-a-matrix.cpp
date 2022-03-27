class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>ans(max(row,col)+1);
    //counting 1s in matix
        for(int i=0;i<row;i++){
            int cnt=0;
            for(int j=0;j<col;j++){
                cnt+=mat[i][j];
            }
            ans[cnt].push_back(i);
        }
        
    vector<int>res;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                if(k>0){
                    res.push_back(ans[i][j]);
                    k--;
                }
            }
        }
       return res;
    }
 
};
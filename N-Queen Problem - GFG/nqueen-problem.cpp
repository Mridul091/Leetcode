// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void helper(int col,int n,vector<vector<vector<int>>>& ans, vector<vector<int>>& board, vector<int>& leftrow,vector<int>& lowerdig, vector<int>& upperdig ){
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row =0;row<n;row++){
            // if(left[row]==0 && lowerdig[row+col]==0 && upperdig[n-1+col-row]==0)
            if(leftrow[row] == 0 && lowerdig[row + col] == 0 && upperdig[n-1 + col -row] == 0){
                board[row][col]=1;
                leftrow[row] = 1;
                lowerdig[row+col] = 1;
                upperdig[n-1+col-row] = 1;
                helper(col+1, n, ans, board, leftrow, lowerdig, upperdig);
                board[row][col]=0;
                leftrow[row] = 0;
                lowerdig[row+col] = 0;
                upperdig[n-1+col-row] = 0;
                
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<vector<int>>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<int> leftrow(n,0), lowerdig(2*n-1,0), upperdig(2*n-1,0);
        helper(0,n,ans,board,leftrow, lowerdig, upperdig);
        
        vector<vector<int>> res;
   
       for(int i=0; i<ans.size(); i++){
           vector<int> sol;
           for(int j=0; j<n; j++){
               for(int k=0; k<n; k++){
                   if(ans[i][j][k] == 1){
                       sol.push_back(k+1);
                   }
               }
           }
           res.push_back(sol);
       }
       sort(res.begin(), res.end());
       return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
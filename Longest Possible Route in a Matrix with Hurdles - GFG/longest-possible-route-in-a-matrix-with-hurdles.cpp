// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    // void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int temp, int ans){
    //     if(x1==x2 && y1==y2){
    //         // if(temp>ans){
    //         //     ans = temp;
    //         //     return;
    //         // }
    //         ans = max(ans, temp);
    //         return;
    //     }
    //     matrix[x1][y1] = 2;
    //     vector<pair<int, int>> adj = {{0,1},{0,-1},{-1,0},{1,0}};
    //     for(auto it: adj){
    //         int newx = x1 + it.first;
    //         int newy = y1 + it.second;
            
    //         if(newx>=0&&newy>=0&&newx<matrix.size()&&newy<matrix[0].size()&&matrix[newx][newy]==1)
    //             helper(matrix, newx, newy,x2, y2, temp+1, ans);
    //     }
    //     matrix[x1][y1] = 1;
    // }
    void path(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd,int pathlength,int &ans)
{
   if(xs==xd&&ys==yd)
   {
       if(pathlength>ans)
       {
           ans=pathlength;
           return;
       }
   }
   matrix[xs][ys]=2;
   
   vector<pair<int,int>>neighbour={{0,1},{0,-1},{-1,0},{1,0}};
   
   for(auto it:neighbour)
   {
       int newx=xs+it.first;
       int newy=ys+it.second;
       
       if(newx>=0&&newy>=0&&newx<matrix.size()&&newy<matrix[0].size()&&matrix[newx][newy]==1)
       {
           path(matrix,newx,newy,xd,yd,pathlength+1,ans);
       }
   }
   
   matrix[xs][ys]=1;
}
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0) return -1;
        int ans= -1;
        path(matrix, xs, ys, xd, yd,0, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
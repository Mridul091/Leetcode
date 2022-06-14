// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(int r, int c, vector<vector<int>>&m, int n, vector<string>& ans, vector<vector<int>>& visited, string temp){
        
        //base case
        if(r==n-1 && c == n-1){
            ans.push_back(temp);
            return;
        }
        if(r+1<n && m[r+1][c]==1 && !visited[r+1][c]){
            visited[r][c] = 1;
            helper(r+1,c,m,n,ans,visited,temp+'D');
            visited[r][c] = 0;
        }
        
        //right
        if(c+1<n && m[r][c+1]==1 && !visited[r][c+1]){
            visited[r][c] = 1;
            helper(r,c+1,m,n,ans,visited,temp+'R');
            visited[r][c] = 0;
        }
        
        //dowm

        
        //left
        if(c-1>=0 && m[r][c-1] == 1 && !visited[r][c-1]){
            visited[r][c] = 1;
            helper(r,c-1,m,n,ans,visited,temp+'L');
            visited[r][c] = 0;
        }
        
        if(r-1>=0 && m[r-1][c]==1 && !visited[r-1][c]){
            visited[r][c] = 1;
            helper(r-1,c,m,n,ans,visited,temp+'U');
            visited[r][c] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>>visited (n, vector<int>(n,0));
        if(m[0][0]==1) helper(0,0,m,n,ans,visited, "");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
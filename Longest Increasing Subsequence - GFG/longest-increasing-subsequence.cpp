// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    // int helper(int n, int ind, int prev_ind, int a[], vector<vector<int>>& dp){
    //     if(ind == n) return 0;
    //     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    //     int len = 0 + helper(n,ind+1,prev_ind, a,dp);
    //     if(prev_ind==-1 || a[ind] > a[prev_ind]){
    //         len = max(len,1+ helper(n,ind+1, ind, a, dp));
    //     }
    //     return dp[ind][prev_ind+1]= len;
    // }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    //   for(int i=0;i<=n;i++)
    //         dp[n][i] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j =i-1;j>=-1;j--){
                int len = 0 + dp[i+1][j+1];
                if(j==-1 || a[i]>a[j])
                    len = max(len, 1 + dp[i+1][i+1]);
                dp[i][j+1] = len;
            }
        }
       return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
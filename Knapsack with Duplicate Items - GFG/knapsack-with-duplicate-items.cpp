// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    // int helper(int ind, int W, int val[], int wt[], vector<vector<int>>& dp){
    //     if(ind==0){
    //         if(wt[0]<=W) return (W/wt[0])*val[0];
    //         else return 0;
    //     }
    //     if(dp[ind][W]!=-1) return dp[ind][W];
    //     int nottaken = helper(ind-1, W, val, wt, dp);
    //     int taken = -1e9;
    //     if(wt[ind]<=W){
    //         taken = val[ind] + helper(ind, W-wt[ind], val, wt, dp);
    //     }
    //     return dp[ind][W] = max(taken , nottaken);
    // }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1,0));
        for(int cap =0;cap<=W; cap++){
            dp[0][cap] =  ((int)cap/wt[0])*val[0];
        }
        
        for(int i=1;i<N;i++){
            for(int cap = 0;cap<=W; cap++){
                int notTaken = dp[i-1][cap];
                
                int taken = -1e9;
                if(wt[i]<=cap)
                    taken = val[i] + dp[i][cap-wt[i]];
                    
                dp[i][cap] = max(notTaken, taken);
            }
        }
        return dp[N-1][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
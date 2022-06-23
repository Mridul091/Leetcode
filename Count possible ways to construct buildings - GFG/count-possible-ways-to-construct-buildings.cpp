// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int helper(int n, vector<vector<int>> &dp, int k){
	    if(n==0) return 1;
	    if(dp[n][k]!=-1) return dp[n][k];
	    long long  take = 0, nottake = 0;
	    if(k==0)
	        take = helper(n-1,dp,1);
	   
	    nottake = helper(n-1,dp, 0);
	    
	    return dp[n][k] = (take+nottake)%1000000007;
	}
	int TotalWays(int N)
	{
	    // Code here
	    vector<vector<int>> dp(N+1,vector<int>(2,-1));
	    long ans = helper(N,dp,0);
	    return (int)((ans*ans)%1000000007);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
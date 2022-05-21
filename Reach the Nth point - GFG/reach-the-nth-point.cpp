// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int mod = 1e9 + 7;
	// memoization
	    
	   // int helper(int n, vector<int>& dp){
	   //     if(n==0) return 1;
		    
		  //  if(dp[n]!=-1) return dp[n];
		    
		  //  int left = helper(n-1, dp);
		  //  int right = 0;
		    
		  //  if(n>=2) right = helper(n-2, dp);
		    
		  //  return dp[n] = (left + right)%mod;
	   // }
	    
		int nthPoint(int n){
		    // Code here

            vector<int> dp(n+1, 0);
            
            dp[0] = 1;
            dp[1] = 1;
            for(int i=2;i<=n;i++){
                dp[i] = (dp[i-1]+dp[i-2])%mod;
		    }
            return dp[n];
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
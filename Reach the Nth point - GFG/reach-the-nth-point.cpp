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

            
            
            int prev = 1;
            int curr = 1;
            for(int i=2;i<=n;i++){
                int curri = (prev + curr)%mod;
                prev = curr;
                curr=curri;
                
		    }
            return curr;
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
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int helper(int *arr, int ind, vector<int>& dp){
        if(dp[ind]!=-1) return dp[ind];
        if(ind==0) return arr[0];
        if(ind==-1) return 0;
        
        int left = helper(arr, ind-1, dp);
        int right = helper(arr, ind-2, dp) + arr[ind];
        
        return dp[ind] = max(left, right);
        
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,0);
	   // return helper(arr, n-1, dp);
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){
	        int left = dp[i-1];
	        int right = arr[i];
	        if(i>1) right  += dp[i-2] ;
	        dp[i] = max(left, right);
	    }
	    return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
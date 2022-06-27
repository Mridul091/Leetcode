// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
    long long int countBT(int n) { 
        // code here
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        long long  x = dp[i-1];
        long long  y = dp[i-2];
        dp[i] = ((x%mod)*((2*y)+x)%mod)%mod;
    }    
    
    return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends
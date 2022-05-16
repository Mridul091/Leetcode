// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // // code here
        // vector<vector<int>> dp(N, vector<int>(k+1,0));
        
        // for(int i=0;i<N;i++) dp[i][0] = 1;
        // if(Arr[0]<=k) dp[0][Arr[0]] = 1;
        
        // for(int i=1;i<N;i++){
        //     for(int target =0;target<=k;target++){
        //         int nottaken = dp[i-1][target];
        //         int taken = 0;
        //         if(Arr[i]<=target) taken = dp[i-1][target-Arr[i]];
        //         dp[i][target] = taken+nottaken;
        //     }
        // }
        // return dp[N-1][k];
        
        int prefix[N];
        prefix[0] = Arr[0];
        
        for(int i =1;i<N;i++)
            prefix[i] = Arr[i] + prefix[i-1];
            
        unordered_map<int,int> mp;
        
        int ans =0;
        for(int i=0;i<N;i++){
            if(prefix[i]==k) ans++;
            
            if(mp.find(prefix[i]-k)!= mp.end())
                ans += mp[prefix[i] - k];
             
            mp[prefix[i]]++;
        }
        return ans;
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends
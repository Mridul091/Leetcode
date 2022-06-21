// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here  
        // long long n_great[n];
        // stack<int> st;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && arr[i] > arr[st.top()])
        //         st.pop();
        //     if(st.empty()) n_great[i] = 0;
        //     else n_great[i] = st.top() + 1;
        //     st.push(i);
        // }
        // while (!st.empty())
        //     st.pop();
        // long long n_small[n];
        
        // for (int i = 0; i < n; i++) {
        //     while (!st.empty() && arr[st.top()] >= arr[i]) {
        //       st.pop();
        //     }
        //     if (st.empty())
        //       n_small[i] = 0;
        //     else
        //       n_small[i] = st.top() + 1;
        //     st.push(i);
        // }
        // long long  maxA = 0;
        //   for (int i = 0; i < n; i++) {
        //     maxA = max(maxA, arr[i] * (n_great[i] - n_small[i] + 1));
        //   }
        //   return maxA;  
        stack < int > st;
         vector<long long> leftsmall(n,-1);
        vector<long long> rightsmall(n,n);
          for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
              st.pop();
            }
            if(!st.empty())
              leftsmall[i] = st.top();
            st.push(i);
          }
          // clear the stack to be re-used
          while (!st.empty())
            st.pop();

          for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
              st.pop();

            // if (st.empty())
            //   rightsmall[i] = n - 1;
            if(!st.empty())
              rightsmall[i] = st.top();

            st.push(i);
          }
          long long  maxA = 0;
          for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i]-1));
          }
          return maxA;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
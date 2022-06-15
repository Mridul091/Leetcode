// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // N: size of input array
    int countOnes(int arr[], int N)
    {
        
        // Your code here
        if(arr[N-1]==1) return N;
        if(arr[0]==0) return 0;
        
        int l = 0;
        int h = N-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid]==0) h = mid-1;
            else{
                if(arr[mid]==1 && arr[mid+1]==0) return mid+1;
                else
                    l = mid+1;
            }
        }
        return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(int arr[], int N, int X)
    {
        
        // Your code here
    // int l = 0;
    // int r = N-1;
    // while(l<=r){
    //     int mid = l + (r-l)/2;
    //     if(arr[mid] <  X) l = mid + 1;
    //     else r = mid - 1;
    // }
    // return r;
    // }
    int res = -1;
    for(int i=0;i<N;i++){
        if(arr[i]==X){
            res = i;
            break;
        }
    }
    return res;
    }

};

// { Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}
  // } Driver Code Ends
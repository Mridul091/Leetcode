// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int bs(int arr[], int start, int end, int key){
        while(start<=end){
            int mid = (start+end)>>1;
            if(arr[mid]==key) return mid;
            else if(arr[mid]>key) end = mid-1;
            else start = mid + 1;
        }
        return -1;
    }
    
    int search(int arr[], int start, int end, int key){
    //complete the function here
        int n = end - start + 1;
	    int ans;
	    int min = 0;
	    while(start<=end){
	        if(arr[start]<arr[end]){
	            min = start;
	            break;
	        } 
	        int mid = (start + end ) >> 1;
	        int next = (mid+1)%n;
	        int prev = (mid + n -1)%n;
	        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                min = mid;
                break;
	        }
	        else if(arr[start]<=arr[mid])
	            start = mid + 1;
	        else
	            end = mid-1;
	    }
	    
	    int fh = bs(arr, 0,min-1, key);
	    int sh = bs(arr, min,n-1, key);
	    
	   // cout << fh << " " << sh << endl;
	    if(fh == -1 && sh == -1)
	        return -1;
	    else if(fh != -1)
	        return fh;
	    else return sh;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends
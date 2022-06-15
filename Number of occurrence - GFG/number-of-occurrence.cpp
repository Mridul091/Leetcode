// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    // code here
	    int l = 0;
        int h = n-1;
        int first_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                first_occ = mid;
                h = mid-1;
            }
            else if(nums[mid]>target)
                h = mid - 1;
            else l = mid + 1;
        }
        if(first_occ==-1) return 0;
        l = 0;
        h = n-1;
        int last_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                last_occ = mid;
                l = mid+1;
            }
            else if(nums[mid]>target)
                h = mid - 1;
            else l = mid + 1;
        }
        return last_occ - first_occ + 1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
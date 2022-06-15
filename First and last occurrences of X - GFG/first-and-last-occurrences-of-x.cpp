// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int l = 0;
        int h = n-1;
        int first_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            
            if(arr[mid]==x){
                first_occ = mid;
                h = mid-1;
            }
            else if(arr[mid]>x)
                h = mid-1;
            else 
                l = mid+1;
        }
        if(first_occ == -1) return {-1};
        l = 0;
        h = n-1;
        int last_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            
            if(arr[mid]==x){
                last_occ = mid;
                l = mid+1;
            }
            else if(arr[mid]>x)
                h = mid-1;
            else 
                l = mid+1;
        }
        
        return {first_occ, last_occ};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends
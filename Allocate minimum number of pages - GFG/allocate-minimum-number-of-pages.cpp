// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isValid(int A[], int N, int M, int mid){
        int student = 1;
        int sum = 0;
        for(int i =0;i<N;i++){
            sum += A[i];
            if(sum > mid){
                student++;
                sum = A[i];
            }
            if(student > M) return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int res = -1;
        int start = *max_element(A, A+N);
        int end =0;
        for(int i=0;i<N;i++)
            end += A[i];
        while(start<=end){
            int mid = (start+end) >>1;
            if(isValid(A,N,M,mid)){
                res = mid;
                end = mid-1;
            }
            else start = mid + 1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
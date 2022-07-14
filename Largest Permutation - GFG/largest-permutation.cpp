// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    void KswapPermutation(int arr[], int n, int k)
    {
        int mp[n+1];
        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }
        for(int i =0;i<n && k>0;i++){
            if(arr[i] == n-i) continue;
            int temp = arr[i];
            swap(arr[mp[n-i]],arr[i]);
            mp[temp] = mp[n-i];
            k--;
        }
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		Solution ob;
		ob.KswapPermutation(arr,n,k);
		for(int i=0;i<n;++i)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}

  // } Driver Code Ends
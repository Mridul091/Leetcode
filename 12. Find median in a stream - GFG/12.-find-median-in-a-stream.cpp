// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    public:
    //Function to insert heap.
    void insertHeap(int &num)
    {
        if(maxpq.empty() || num<maxpq.top()){
       		maxpq.push(num);
  		}
       	else minpq.push(num);
        
        if((int)(minpq.size()-maxpq.size())>1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        else if((int)(maxpq.size()-minpq.size())>1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {   int size = maxpq.size() + minpq.size();
        double ans;
        if(size%2==0){
            ans = (maxpq.top() + minpq.top())/2.0;
        }
        else{
            if(maxpq.size()>minpq.size()) ans = maxpq.top();
            else ans = minpq.top();
        }
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
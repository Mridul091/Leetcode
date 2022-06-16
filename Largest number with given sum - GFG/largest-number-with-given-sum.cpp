// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        string res = "";
        if(9*n < sum){
            res+= "-1";
            return res;
        } 
        while(n--){
            if(sum>=9){
                res+= '9';
                sum -= 9;
                
            }
            else if(sum>0){
                res+= to_string(sum);
                sum = 0;
            }
            else{
                res+='0';
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string str)
    {
        // Your code here
        stack<char> st;
        for(int i =0;i<str.size();i++){
            if(st.empty())
                st.push(str[i]);
            else{
            if(st.top()==str[i])
                st.pop();
            else st.push(str[i]);
            }
        }
       
        string res = "";
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
            
        reverse(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
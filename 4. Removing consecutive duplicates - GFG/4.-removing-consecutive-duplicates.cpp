// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty())
                st.push(s[i]);
            
            if(st.top()==s[i]) continue;
            else st.push(s[i]);
        }
        string res="";
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
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
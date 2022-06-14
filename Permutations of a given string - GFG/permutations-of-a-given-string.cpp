// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    
	    void helper(int ind, vector<string>& ans, string& S ){
	        
	        if(ind == S.size()){
	            ans.push_back(S);
	            return ;
	        }
	        unordered_set<int> seen;
	        for(int i = ind;i<S.size();i++){
	            if(seen.find(S[i])!=seen.end()) continue;
	            seen.insert(S[i]);
	            swap(S[ind],S[i]);
	            helper(ind+1, ans, S);
	            swap(S[ind], S[i]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    helper(0,ans, S);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
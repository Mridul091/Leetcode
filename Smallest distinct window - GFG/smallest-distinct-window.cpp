// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        unordered_set<int> s;
        for(int i=0;i<str.size();i++)
            s.insert(str[i]);
        
        unordered_map<char, int> mp;
        int len = 1e9;
        int j = 0;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
            if(mp.size()==s.size()){
                while(mp[str[j]]>1){
                    mp[str[j++]]--; 
                }
                len = min(len, i-j +1);
            }
            
        }
        return len;
    }
};
//  set<char>s; unordered_map<char,int>m;
//       for(char c:str)
//       s.insert(c);
       
//         int i =0, j = 0, ans = str.size(), n = s.size(); 
        
//         while(i<str.size())
//         {    m[str[i]]++; 
//             if(m.size()==n)
//             {
//                 while(m[str[j]]>1) m[str[j++]]--;
//                 ans = min(ans, i-j+1); 
//             }
//             i++;  
//         }
//         return ans;

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends
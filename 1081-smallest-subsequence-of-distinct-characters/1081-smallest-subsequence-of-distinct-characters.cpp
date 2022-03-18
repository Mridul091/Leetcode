class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(26,false);
        
        vector<int> last_ind(26,0);
        for(int i=0;i<s.length();i++){
            last_ind[s[i]-'a'] = i;
        }
        
        stack<int> st;
        for(int i=0;i<s.size();i++){
            int curr = s[i]-'a';
            if(seen[curr])
                continue;
            
            while(st.size()>0 && st.top() > s[i] &&  i<last_ind[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
                }
            st.push(s[i]);
            seen[curr]=true;
        }
        string res="";
        while(st.size()>0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
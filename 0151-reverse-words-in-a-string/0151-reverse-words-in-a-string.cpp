class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return s;
        stack<string> st;
        
        for(int i = 0;i<s.size();i++){
            string temp;
            if(s[i]==' ') continue;
            
            while(i<s.size() && s[i]!=' '){
                temp+=s[i++];
                
            }
            st.push(temp);
            
        }
        
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
            if(!st.empty()) res += ' ';
            
        }
        return res;
    }
};
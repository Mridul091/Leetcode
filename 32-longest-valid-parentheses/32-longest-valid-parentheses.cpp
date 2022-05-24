class Solution {
public:
    int longestValidParentheses(string s) {

        int len = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int open = 1;
                int closed = 0;
                for(int j=i+1;j<s.size();j++){
                    if(s[j]=='(') open++;
                    if(s[j]==')') closed++;
                    int maxlen;
                    if(open==closed){
                        maxlen = j-i+1;
                        len = max(maxlen,len);
                    }
                    if(closed>open) break;
                    
                }
            }
            
        }
        return len;
    }
};
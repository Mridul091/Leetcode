class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') s1.push('(');
            else{
                if(!s1.empty() && s1.top()=='(') s1.pop();
                else s1.push(')');
            }
        }
        return s1.size();
    }
};
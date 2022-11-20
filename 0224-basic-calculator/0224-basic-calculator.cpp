class Solution {
public:
    int calculate(string s) {
        
        int i = 0, tmp = 0, n = s.size();
        char op = '+';
        
        while(i < n)
        {
            if(s[i] == '+' || s[i] == '-')
                op = s[i++]; 
            else if(s[i] == '(')
            {
                string s2;
                i++;
                int a = 1;
                while(i < n && a)
                {
                    if(s[i] == '(')
                        a++;
                    else if(s[i] == ')')
                        a--;
                    
                    if(a == 0)
                        break;
                    
                    s2 += s[i++];
                }
                
                i++;
                if(op == '+')
                    tmp += calculate(s2);
                else
                    tmp -= calculate(s2);
            }
            else if(s[i] != ' ')
            {
                int cnt = 0;
                while(i < n && isdigit(s[i]))
                    cnt = cnt * 10 + (s[i++] - '0');
                
                if(op == '+')
                    tmp += cnt;
                else
                    tmp -= cnt;
            }
            else
                i++;
        }
        
        return tmp;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n==0) return 0;
        int i=0;
        while(i<n && s[i]==' ') i++;
        int sign = 1;
        if(s[i]=='+' || s[i]=='-'){
            sign = s[i]=='-'?-1:1;
            i++;
        }
        long res = 0;
        while(i<n && s[i]>='0' && s[i] <='9'){
            int dig = (s[i]-'0')*sign;
            res = res*10 + dig;
            if(sign==1 && (res>INT_MAX)) return INT_MAX;
            if(sign==-1 && (res<INT_MIN)) return INT_MIN;
            
            i++;
        }
        return res;
    }
};
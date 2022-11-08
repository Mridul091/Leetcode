class Solution {
public:
    string makeGood(string s) {
        int n=s.size(),i=0;
        if(n==0 || n==1) 
            return s;
        while(i<n-1){
            if(abs(s[i]-s[i+1])==32){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i); 
                if(i>0)
                    i--;
                n=s.size();
            }
            else
                i++;
        }
        return s;
    }
};
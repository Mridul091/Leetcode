class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt =0;
        int k =0;
        if(s[n-1]==' ' && k<n){
            while(s[n-1-k]==' '){
                k++;
            }
        }
        n = n-k;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ')
                break;
            cnt++;
        }
        return cnt;
    }
};
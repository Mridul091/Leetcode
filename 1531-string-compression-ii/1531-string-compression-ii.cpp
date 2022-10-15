int mem[100][27][101][100];
class Solution {
public:
    int len;
    string ss;
    int new_d(int x){
        return x == 1 || x == 9 || x == 99;
    }
    int sol(int idx, int prev, int c, int k) {
        
        if (k < 0) return INT_MAX;
        if (idx == len)  return 0;
                
        int &ret = mem[idx][prev][c][k];
        if (~ret) return ret;
        
        ret = INT_MAX;
        ret = min(ret, sol(idx + 1, prev, c, k - 1) ); 
        
        if (ss[idx]-'a' != prev) ret = min(ret, sol(idx + 1, ss[idx] - 'a', 1, k) + 1);  
        else ret = min(ret, sol(idx + 1, prev, c + 1, k) + (new_d(c) ? 1 : 0) ); 

        return ret;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(mem, -1, sizeof(mem));
        len = s.length();
        ss = s;
        return sol(0, 26, 0, k);
    }
};
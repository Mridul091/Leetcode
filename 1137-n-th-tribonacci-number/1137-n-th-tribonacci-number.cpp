class Solution {
public:
    int tribonacci(int n) {
        // while(n==0)
        //     return 0;  
        // while(n==2 || n==1)
        //     return 1;
        
        int prev3 = 0;
        int prev2 = 1;
        int prev = 1;
        if(n==0) return 0;
        for(int i=3;i<=n;i++){
            int curr = prev3+prev2+prev;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        
     return prev;
    }
};
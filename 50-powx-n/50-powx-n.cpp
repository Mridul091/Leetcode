class Solution {
public:
    double myPow(double x, int n) {
        
        
//         if(n==0) return 1;
        
//         if(n<0){
//             n = -n;
//             x = 1/x;
//         }
//         double ans = x;
//         while(n-1){
//             x=x*ans;
//             n--;
//         }
//         return x;
        double ans = 1.0;
        long long p = n;
        if(p<0) p = -p;
        while(p){
            //even
            if(p%2==0){
                x = x*x;
                p = p/2;
            }
            else{
                ans = x* ans;
                p = p-1;
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};
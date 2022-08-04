class Solution {
public:
    
    int gcd(int a, int b) {
        while(b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    
    int mirrorReflection(int p, int q) {
        int lcm = (p*q)/gcd(p,q);
        int a = lcm/p;
        int b = lcm/q;
        
        if(a%2==0 && b%2==1) return 0;
        if(a%2==1 && b%2==1) return 1;
        if(a%2==1 && b%2==0) return 2;
        return -1;
    }
};
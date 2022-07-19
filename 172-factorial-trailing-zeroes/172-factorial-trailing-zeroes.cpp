class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int cnt = 0;
        int k =n;
        int i =1;
        cout << k << endl;
        while(k>1){
            k = n/(pow(5,i));
            cnt+= k;
            i++;
        }
        return cnt;
    }
};
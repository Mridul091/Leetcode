class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto it: rolls)
            sum += it;
        
        int rem = mean*(n+m) - sum;
        if(rem < n ||  rem > 6*n) return {};
        // int rem_int = rem/n;
        // return {1,0};
        
        int rem_var = rem/n;
        int rem_val = rem%n;
        vector<int> res(n, rem_var);
        for(int i =0;i<rem_val;i++){
            ++res[i];
        }
        return res;
    }
};
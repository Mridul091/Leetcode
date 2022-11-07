class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int p1 = 1, p2=1;
        // int n = nums.size();
        // vector<int>answer(n,1);
        // for(int i=0;i<n;i++){
        //     answer[i]*=p1;
        //     p1*=nums[i];
        //     int j= n-i-1;
        //     answer[j]*=p2;
        //     p2*=nums[j];
        // }
        // return answer;
        int n = nums.size();
        vector<int> ans(n,1);
        
        int prefix = 1;
        for(int i = 0;i<n;i++){
            ans[i] = prefix;
            prefix = prefix*nums[i];
        }
        
        int postfix = 1;
        for(int i = n-1;i>=0;i--){
            ans[i] = ans[i]*postfix;
            postfix = postfix*nums[i];
        }
        
        return ans;
    }
};
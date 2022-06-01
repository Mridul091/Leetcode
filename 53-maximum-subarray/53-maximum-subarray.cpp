class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //BRUTE FORCE SOLUTION\U0001f622
        // int n = nums.size();
        // if (n == 1) {
        //     return nums[0];
        // }
        // int max_sum = 0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         cout << sum << " ";
        //         if(max_sum < sum)
        //             max_sum = sum;
        //     }
        //     cout << endl;
        // }
        // return max_sum;
        
        //KADANE ALGORITHM
        
        int n = nums.size();
        int sum = 0;
        int max_sum = -1e9;
        for(int i=0;i<n;i++){

            
            sum += nums[i];
            if(max_sum < sum)
                max_sum = sum;
            
            if(sum<0) sum = 0;
            
            
        }
        return max_sum;
    }
};
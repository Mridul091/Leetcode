class Solution {
public:
//     int helper(vector<int>& nums, int x, int i, int j){
//         if(x==0){
//             return 0;
//         }
//         if(x<0)
//             return -1;
//         int left = 1+ helper(nums, x-nums[i], i++,j);
//         int right =1+ helper(nums, x-nums[j],i,j--);
//         cout << left << " " << right << endl;
//         return min(left, right);
        
//     }
    int minOperations(vector<int>& nums, int x) {
        int sum1 =0;
        for(auto it: nums)
            sum1+= it;
        if(sum1<x) return -1;
        if(sum1 == x ) return nums.size();
        sum1 -= x;
        int curr_sum =0, start =0, max_size =0;
        for(int i=0;i<nums.size();i++){
            curr_sum += nums[i];
            
            while(curr_sum > sum1)
                curr_sum -= nums[start++];
            
            if(curr_sum == sum1)
                max_size = max(max_size, i-start+1);
        }
        return (max_size==0) ? -1 : nums.size()-max_size;
    }
};
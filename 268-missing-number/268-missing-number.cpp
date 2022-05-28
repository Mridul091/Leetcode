class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_nums=0;
        for(auto it: nums)
            sum_nums+=it;
        
        int sum_total = (n*(n+1))/2;
        return sum_total - sum_nums;
        
    }
};
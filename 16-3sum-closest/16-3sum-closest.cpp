class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int diff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < diff){
                    diff = abs(target-sum);
                    res = sum;
                }
                else if(sum < target) j++;
                else k--;
            }
        }
        return res;
    }
};
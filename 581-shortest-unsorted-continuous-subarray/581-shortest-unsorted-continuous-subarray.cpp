class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = n;
        
        int curr_min = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(curr_min> nums[i]) curr_min = nums[i];
            if(curr_min < nums[i]) start = i;
        }
        
        int curr_max = INT_MIN;
        for(int i=0;i<n;i++){
            if(curr_max < nums[i]) curr_max = nums[i];
            if(curr_max > nums[i]) end = i;
        }
        
        if(start==-1) return 0;
        return end-start+1;
    }
};
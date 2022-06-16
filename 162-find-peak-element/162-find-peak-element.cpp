class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) 
            return 0;
        int start = 0;
        int end = nums.size() - 1;
       
        int ans;
        while(start<=end){
            int mid = (start+end) >> 1;
            if(mid>0 && mid < n-1){
                if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1]){
                    ans = mid;
                    break;
                }
                    
                else if(nums[mid-1] > nums[mid])
                    end = mid-1;
                else start = mid + 1;
            }
            else if(mid==0){
                if(nums[0]>nums[1]){
                    ans = 0;
                    break;
                }
                else{
                    ans = 1;
                    break;
                }
            }
            else if(mid==n-1){
                if(nums[n-1] > nums[n-2]){
                    ans = n-1;
                    break;
                } 
                else{
                    ans = n-2;
                    break;
                } 
            }
        }
        return ans;
    }
};
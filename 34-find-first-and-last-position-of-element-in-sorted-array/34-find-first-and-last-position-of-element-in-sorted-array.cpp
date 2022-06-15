class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int first_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                first_occ = mid;
                h = mid-1;
            }
            else if(nums[mid]>target)
                h = mid - 1;
            else l = mid + 1;
        }
        l = 0;
        h = nums.size()-1;
        int last_occ = -1;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==target){
                last_occ = mid;
                l = mid+1;
            }
            else if(nums[mid]>target)
                h = mid - 1;
            else l = mid + 1;
        }
        
        return {first_occ, last_occ};
    }
};
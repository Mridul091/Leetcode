class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = (l+h) >> 1;
            if(nums[mid]==target) return true;
            if((nums[mid] == nums[l]) && (nums[h]==nums[mid])){
                l++;
                h--;
            }
            else if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target < nums[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else{
                if(target> nums[mid] && target<=nums[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return false;
    }
};
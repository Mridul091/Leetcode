class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1e9;
        int ind =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
                ind = i;
            }
        }
        int sec_max = -1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sec_max && i!=ind){
                sec_max = nums[i];
            }
        }
        if(max>=2*sec_max) return ind;
        else return -1;
    }
};
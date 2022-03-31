class Solution {
public:
    
    bool helper(vector<int>& nums, int m, int max ){
        int part=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=max)
                sum+=nums[i];
            else{
                sum=nums[i];
                part++;
            }
                
        }
        return (part+1)<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l =0,h=0,sum=0;
        for(int i=0;i<nums.size();i++){
            h+=nums[i];
            l=max(l,nums[i]);
        }
        while(l<=h){
            int mid = (l+h) >> 1;
            if(helper(nums, m, mid))
                h=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};
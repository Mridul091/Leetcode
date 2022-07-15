class Solution {
public:

    bool helper(vector<int>& nums, int p1, int p2, int flag, int n, int i, int j){
        
        if(i>j){
            if(p1>=p2) return true;
            return false;
        }
        
        if(flag%2==0){
            
            return helper(nums,p1+nums[i], p2, flag+1, n-1,i+1,j) || helper(nums,p1+nums[j], p2, flag+1, n-1,i,j-1);
        }
        else{
             return  helper(nums,p1, p2+nums[i], flag+1, n-1,i+1,j) && helper(nums,p1, p2+nums[j], flag+1, n-1,i,j-1);
        }
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        return helper(nums,0,0,0,n, 0 ,n-1);
    }
};
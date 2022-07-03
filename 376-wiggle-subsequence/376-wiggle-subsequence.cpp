class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1 || n==2) return 1;
//         vector<bool> diff(n-1,0);
        
//         for(int i=0;i<n-1;i++){
//             if((nums[i] - nums[i+1]) >= 0)
//                 diff[i] = 1;
//             else
//                 diff[i] = 0;
//         }
//         for(int i=0;i<diff.size();i++)
//             cout << diff[i] << " ";
//         int ans = 1;
//         for(int i =1;i<diff.size()-1;i++){
//             if(diff[i] != diff[i+1]) ans++;
//         }
//         return ans +1;
//     }
        int size=nums.size();
        int peak=1, valley=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};
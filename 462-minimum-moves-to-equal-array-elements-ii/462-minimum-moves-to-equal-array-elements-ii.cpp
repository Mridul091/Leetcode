class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = nums[n/2];
        int cnt = 0;
        for(auto it: nums){
            cnt += abs(it-mid);
        }
        return cnt;
//         long mini = INT_MAX;
        
//         for(int i=0;i<n;i++){
//             long cnt = 0;
//             for(int j =0;j<n;j++){
//                 cnt += abs(nums[i]-nums[j]);
//             }
//             mini = min(mini, cnt);
//         }
        // return (int)mini;
    }
};
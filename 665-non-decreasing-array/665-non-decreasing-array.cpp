class Solution {
public:
    bool checkPossibility(vector<int>& N) {
//         int n = nums.size();
//         if(n==1) return true;
//         int cnt = 0;
//         for(int i=n-1;i>0;i--){
//             if(nums[i]<nums[i-1]){
//                 nums[i-1] = nums[i] - 1;
//                 cnt++;
               
//             }
//              if(cnt>1) break;
//         }
//         for(auto it: nums){
//             cout << it << " ";
//         }
//         return cnt<=1;
        for (int i = 1, err = 0; i < N.size(); i++)
            if (N[i] < N[i-1])
                if (err++ || (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1]))
                    return false;
        return true;
    }
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = arr.size();
        // int sum1 = (n*(n+1))/2;
        // int sum2 = 0;
        // for(auto it: arr)
        //     sum2+=it;
        // cout << sum1 << " " << sum2 << " ";
        // int ans  = n - (sum1 - sum2);
        // return ans;
        
//         return sum2-sum1;
        
//         sort(arr.begin(),arr.end());
//         int ans;
//         for(int i=1;i<n;i++){
//             if(arr[i-1]==arr[i]){
//                 ans=arr[i];
//                 break;
//             }
                
//         }
//         return ans;
        
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
};
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
//         int sum1 = (n*(n-1))/2;
//         int sum2 = 0;
//         for(auto it: arr)
//             sum2+=it;
        
//         return sum2-sum1;
        
        sort(arr.begin(),arr.end());
        int ans;
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]){
                ans=arr[i];
                break;
            }
                
        }
        return ans;
    }
    
};
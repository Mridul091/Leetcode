class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
//         int cnt = 0;
//         int n = properties.size();
//         int m = properties[0].size();
        
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 if(i==j) continue;
//                 else{
//                     if(properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]){
//                         cnt++;
//                         break;
//                     } 
//                 }
//             }
//         }
//         return cnt;
        
        sort(nums.begin(), nums.end(), cmp);
        
        int cnt= 0;
        int maxi = INT_MIN;
        for(auto n: nums){
            if(maxi > n[1]) cnt++;
            else maxi = n[1];
        }
        return cnt;
    }
};
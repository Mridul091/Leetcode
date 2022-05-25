// class Solution {
// public:
//     static bool comp(const vector<int>& a,const vector<int>& b){
//         if(a[0]==b[0]) return a[1] > a[1];
//         return a[0] < b[0];
//     }
//     int maxEnvelopes(vector<vector<int>>& arr) {
//         sort(arr.begin(),arr.end(),comp);
//         int n=arr.size();
//         vector<int> res;
//         // for(auto e: arr){
//         //     cout<<e[0]<<","<<e[1]<<"    ";
//         // }
//         for(int i=0;i<n;i++){
//             auto it=lower_bound(res.begin(),res.end(),arr[i][1]);
//             if(it==res.end()) {
//                 res.push_back(arr[i][1]);
//             } 
//             else {
//                 *it=arr[i][1];
//             }
//         }
//         return res.size();
//     }
    
// };
class Solution {
public:
    static bool cmp(const vector<int> &a , const vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int n=arr.size();
       /*
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        for(int end=1;end<n;end++){
            for(int start=0;start<end;start++){
                if(arr[end][1]>arr[start][1]){
                    dp[end]=max(dp[end],dp[start]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());*/ //O(n^2 approach)
        
        
        vector<int> res;
        // for(auto e: arr){
        //     cout<<e[0]<<","<<e[1]<<"    ";
        // }
        for(int i=0;i<n;i++){
            auto it=lower_bound(res.begin(),res.end(),arr[i][1]);
            if(it==res.end()) {
                res.push_back(arr[i][1]);
            } 
            else {
                *it=arr[i][1];
            }
        }
        return res.size();  //O(NlogN BS APPROACH)
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
//         for(int i=0;i<n;i++){
//             int a = intervals[i][0];
//             int b = intervals[i][1];
            
//             for(int j=i+1;j<n;j++){
//                 int c = intervals[j][0];
//                 int d = intervals[j][1];
//                 // checking for overlap condition
//                 if(b>=c){
//                     b = max(b,d);
//                     i=j;
//                 }
//             }
//             res.push_back({a,b});
//         }
        
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(res.back()[1]>=intervals[i][0]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
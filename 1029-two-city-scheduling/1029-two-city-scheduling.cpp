class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int>ans(n);
        int total=0;
        for(int i=0;i<n;i++){
            total+=costs[i][0];
            ans[i] = costs[i][1] - costs[i][0];
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n/2;i++){
            total+= ans[i];
        }
        return total;
        }
};
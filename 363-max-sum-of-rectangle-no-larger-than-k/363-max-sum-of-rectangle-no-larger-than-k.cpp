class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        
        for(int c =0;c<m;c++){
            vector<int> temp(n);
            for(int r= c;r<m;r++){
                for(int i = 0;i<n;i++)
                    temp[i] += matrix[i][r];
                set<int> s = {0};
                int pre_sum = 0;
                for(int x: temp){
                    pre_sum += x;
                    auto it = s.lower_bound(pre_sum - k);
                    if(it!=s.end()){
                        ans = max(ans, pre_sum - *it);
                    }
                    s.insert(pre_sum);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<pair<int, int>> v;
        for(int i =0;i<n;i++) v.push_back({numbers[i],i});
        int s = 0, e = n-1;
        while(s<e){
        int sum = v[s].first + v[e].first;
        if(sum == target) return {v[s].second+1, v[e].second+1};
        else if(sum > target) e--;
        else s++;
        }
        return {-1, -1};
    }
};
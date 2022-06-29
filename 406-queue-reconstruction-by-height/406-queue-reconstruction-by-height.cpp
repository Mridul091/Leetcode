class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] < b[1];
        else return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(),cmp);
        for(auto num: people){
            res.insert(res.begin() + num[1], num);
        }
        return res;
    }
};
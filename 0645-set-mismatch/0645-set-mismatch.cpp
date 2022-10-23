class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int rep_num =0, find_num =0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
            if(mp[it]==2){
                rep_num = it;
                break;
            }
        }
        
        for(auto it: nums) sum += it;
        sum -= rep_num;
        int exp_num = (n*(n+1))/2;
        
        find_num = exp_num - sum;
        
        return {rep_num, find_num};
    }
};
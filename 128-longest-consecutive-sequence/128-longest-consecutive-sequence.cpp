class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mp.insert(nums[i]);
        int len =0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()) continue;
            else{
                int next = nums[i];
                while(mp.find(next)!=mp.end())
                    next++;
                
                if(len < next - nums[i])
                    len = next - nums[i];
            }
        }
        return len;
    }
};
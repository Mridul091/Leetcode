class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        // if(n<6) return false;
    
        map<int, int> cnt;
        for(int i =0;i<nums.size();i++) cnt[nums[i]]++;
        
        for(auto it: nums){
            if(cnt[it]==0) continue;
            int freq = cnt[it], curr = it, k = 0;
            while(cnt.count(curr) && cnt[curr] >= freq){
                freq = max(freq, cnt[curr]);
                cnt[curr]--;
                k++;
                curr++;
            }
            if(k < 3) return false;
        }
        return true;
    }
};
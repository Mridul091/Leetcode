class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        
        int n = nums.size();
        for(int i =0;i<n;i++){
            while(!q.empty() && i-q.front()>=k) q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            
            q.push_back(i);
            
            if(i+1 >= k ) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
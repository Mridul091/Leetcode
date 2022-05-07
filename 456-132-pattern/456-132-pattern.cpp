class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int mini = INT_MAX;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(!st.empty()) mini = min(mini,st.top().first);
            
            while(!st.empty() && st.top().first<nums[i]) st.pop();
            
            if(!st.empty()){
                if(st.top().first>nums[i] && nums[i]>st.top().second) return true;
            }
            
            st.push({nums[i], mini});
        }
        return false;
    }
};
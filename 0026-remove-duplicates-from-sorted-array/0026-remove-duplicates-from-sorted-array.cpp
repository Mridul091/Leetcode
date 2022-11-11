class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i]==st.top()) continue;
            else st.push(nums[i]);
        }
        int k = st.size();
        nums.resize(k);
        for(int i =0;i<k;i++){
            nums[i] = st.top();
            st.pop();
        }
        reverse(nums.begin(),nums.end());
        return k;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int find;
//         int n2 = nums2.size();
//         vector<int> ans;
//         for(int i=0;i<n1;i++){
//             for(int j=0;i<n2;j++){
//                 if(nums1[i]==nums2[j]){
//                     find =j;
//                     break;
//                 } 
   
//             }
//             bool flag = false;
//             for(int k = find;k<n2;k++){
//                 if(nums2[find] < nums2[k]){
//                     flag = true;
//                     ans.push_back(nums2[k]);
//                     break;
//                 }
//             }
//             if(!flag) ans.push_back(-1);
//         }
//         return ans;
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            if(st.empty())
                mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
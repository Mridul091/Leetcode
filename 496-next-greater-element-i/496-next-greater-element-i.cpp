class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int find;
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            for(int j=0;i<n2;j++){
                if(nums1[i]==nums2[j]){
                    find =j;
                    break;
                } 
   
            }
            bool flag = false;
            for(int k = find;k<n2;k++){
                if(nums2[find] < nums2[k]){
                    flag = true;
                    ans.push_back(nums2[k]);
                    break;
                }
            }
            if(!flag) ans.push_back(-1);
        }
        return ans;
    }
};
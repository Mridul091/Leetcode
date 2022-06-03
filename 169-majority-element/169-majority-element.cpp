class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // vector<int> freq;
        unordered_map<int, int> freq;
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>n/2){
                ans = nums[i];
            }
            cout << freq[nums[i]] << " ";
        }
        return ans;
        // int max = -1e9;
        // int ans;
        // for(int i =0;i<freq.size();i++){
        //     if(max<freq[i]){
        //         max = freq[i];
        //         ans = i;
        //     }
        // }
        // return ans;
    }
};
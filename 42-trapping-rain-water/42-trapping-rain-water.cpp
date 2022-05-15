class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n];
        int suffix[n];
        int max_pre = INT_MIN;
        for(int i=0;i<n;i++){
            max_pre = max(max_pre, height[i]);
            prefix[i] = max_pre;
            cout << prefix[i] <<" ";
        }
        cout << endl;

        int max_suf = INT_MIN;
        for(int i=n-1;i>=0;i--){
            max_suf = max(max_suf, height[i]);
            suffix[i] = max_suf;
            
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans += min(prefix[i],suffix[i])- height[i];
        }
        
        return ans;
    }
};
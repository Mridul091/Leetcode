class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n = nums.size();
        int ans=0;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            int cnt = 0;
            while(x>0) {
                cout << x << " ";
                x/=10;
                cnt++;
            }
            cout << endl;
            if(cnt%2==0)
                ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i =0;i<n;i++) mp[arr[i]]++;
        
        
        vector<int> temp;
        for(auto& p : mp) temp.push_back(p.second);
        
        sort(temp.begin(), temp.end(), greater<int>());
        int ans = 0;
        int tar = n/2;
        for(int x: temp){
            ++ans;
            tar -= x;
            if(tar <= 0) break;
        }
        return ans;
    }
};
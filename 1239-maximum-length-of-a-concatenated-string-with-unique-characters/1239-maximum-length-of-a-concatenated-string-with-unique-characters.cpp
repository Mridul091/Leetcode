class Solution {
public:
    int ans = 0;
   void helper(string& temp, vector<string>& arr, int ind){
        
        if(ind > arr.size()-1) return;
        
        unordered_map<char, int> mp;
        for(int i =0;i<temp.size();i++){
            mp[temp[i]]++;
            if(mp[temp[i]]>1) return;
        }
        int len = temp.size();
        ans = max(ans, len);
        for(int i=ind+1;i<arr.size();i++){
            string dummy = temp + arr[i];
            helper(dummy, arr, i);
        }
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        for(int i =0;i<n;i++){
            string temp = arr[i];
            helper(temp, arr, i);
        }
        return ans;
    }
};
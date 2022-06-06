class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        // vector<int> freq(256, 0);
        // int maxi= -1e9;
        // string ans = "";
        // for(int i=0;i<n;i++){
        //     int ind = s[i] - 'a';
        //     if(freq[ind]==0){
        //         ans+= s[i];
        //         freq[ind]++;
        //     }
        //     else{
        //         int k = ans.size();
        //         if(maxi < k)
        //             maxi = k;
        //         ans = "";
        //         for(int j=0;j<256;j++){
        //             if(freq[j]==0) continue;
        //             else freq[j] =0;
        //         }
        //     }
        // }
        // if(maxi < ans.size())
        //     maxi = ans.size();
        // return maxi;
                unordered_map<char,int> map;
        int l=0,r=0,ans=0;
        while(l<=r&&r<s.length())
        {
            if(map[s[r]]==0)
            {
                map[s[r]]++;
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                map[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};


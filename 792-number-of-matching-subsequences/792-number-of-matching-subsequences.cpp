class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> mp;
        for(int i =0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto x: mp){
            int j =0;
            int k =0;
            string check = x.first;
            int n = check.size();
            while(j<n && k < s.size()){
                if(check[j]==s[k]){
                    j++;
                    k++;
                }
                else{
                    k++;
                }
                if(j==n) count += x.second;
            }
        }
        return count;
    }
};
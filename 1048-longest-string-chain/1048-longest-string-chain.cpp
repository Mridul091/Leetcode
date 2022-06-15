class Solution {
public:
    
    static bool compare(string s1, string s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),compare);
        int len = 1;
        unordered_map<string, int > dp;
        for(auto word: words){
            dp[word] = 1;
            for(int i=0;i<word.size();i++){
                string pre = word.substr(0,i) + word.substr(i+1);
                if(dp.find(pre)!=dp.end()){
                    dp[word] = dp[pre]+1;
                    len = max(len,dp[word]);
                }
            }
        }
        return len;
    }
};
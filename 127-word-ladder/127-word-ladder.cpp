class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp;
        for(auto it: wordList)
            mp.insert(it);
        int ans = 1;
        if(mp.find(endWord)==mp.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                string word = q.front();
                q.pop();
                if(word==endWord) return ans;
                
                mp.erase(word);
                for(int j=0;j<word.size();j++){
                    char x = word[j];
                    for(int k =0;k<26;k++){
                        word[j] = 'a' + k;
                        if(mp.find(word)!=mp.end()) q.push(word);
                    }
                    word[j] = x;
                }
            }
            ans++;
        }
        return 0;
    }
};
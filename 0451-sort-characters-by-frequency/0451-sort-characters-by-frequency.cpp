class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i = 0;i<s.size();i++) m[s[i]]++;
        sort(s.begin(), s.end(), [&m](char a, char b) -> bool {
           if(m[a] == m[b]) {
               return a < b;
           } 
           return m[a] > m[b];
        });
        return s;
        
    }
};
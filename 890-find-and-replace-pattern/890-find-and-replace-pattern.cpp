class Solution {
public:
    
    bool helper(string check, string pattern){
        
        unordered_map<char, char> nodes;
        unordered_map<char, int> visited;
        
        for(int i =0;i<pattern.size();i++){
            
            char c = check[i];
            char s = pattern[i];
            
            if(nodes[s] && nodes[s]!=c || !nodes[s] && visited[c]==1) return false;
            else {
                nodes[s] = c;
                visited[c] = 1;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i =0;i<words.size();i++){
            
            string check = words[i];
            if(helper(check, pattern)) ans.push_back(check);
        }
        
        return ans;
    }
};
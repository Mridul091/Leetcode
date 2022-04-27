class Solution {
public:
    
    static const int N = 1e5 + 1;
    vector<int> adj[N];
    bool vis[N];
    
    void dfs(string& s, int i, vector<char> &chars, vector<int> &ind){
        chars.push_back(s[i]);
        ind.push_back(i);
        
        vis[i] = true;
        for(int n: adj[i]){
            if(!vis[n]){
                dfs(s,n,chars,ind);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(auto it: pairs){
            int src = it[0];
            int dis = it[1];
            
            adj[src].push_back(dis);
            adj[dis].push_back(src);
        }
        
        for(int i = 0;i<s.size();i++){
            if(!vis[i]){
                vector<char> chars;
                vector<int> ind;
                
                dfs(s,i,chars, ind);
                sort(chars.begin(), chars.end());
                sort(ind.begin(), ind.end());
                for(int j=0;j<chars.size();j++)
                    s[ind[j]] = chars[j];
            }
        }
        return s;
    }
};
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> mp;
//         for(auto str: wordList) mp.insert(str);
//         if(mp.find(endWord)==mp.end()) return {};
        
//         vector<vector<string>> res;
//         queue<vector<string>> q;
//         q.push({beginWord});
//         while(!q.empty()){
//             int sz = q.size();
//             bool flag = false;
//             unordered_set<string> vis;
//             while(sz--){
//                 auto curr_path = q.front();
//                 q.pop();
//                 string lst_wrd = curr_path.back();
//                 for(int i =0;i<lst_wrd.size();i++){
//                     char c = lst_wrd[i];
//                     for(int j =0;j<26;j++){
//                         lst_wrd[i] = 'a' + j;
//                         if(mp.find(lst_wrd)!=mp.end()){
//                             curr_path.push_back(lst_wrd);
                            
//                             if(lst_wrd == endWord){
//                                 res.push_back(curr_path);
//                                 flag = true;
//                             }
//                             else q.push(curr_path);
                            
//                             vis.insert(lst_wrd);
//                             curr_path.pop_back();
//                         }
//                     }
                    
//                     lst_wrd[i] = c;
//                 }
//             }
            
//             for(auto it: vis){
//                 if(mp.count(it)) mp.erase(it);
//             }
//             if(flag) break;
//         }
//         return res;
//     }
// };
class Solution {
public:
bool able(string s,string t){
    if(s.length()!=t.length())
        return false;
    int c=0;
    for(int i=0;i<s.length();i++)
        c+=(s[i]!=t[i]);
    return c==1;
}
void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int sr,int ds){
    vector <int> dist(n,1005);
    queue <int> q;
    q.push(sr);
    parent[sr]={-1};
    dist[sr]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int u:g[x]){
            if(dist[u]>dist[x]+1){
                dist[u]=dist[x]+1;
                q.push(u);
                parent[u].clear();
                parent[u].push_back(x);
            }
            else if(dist[u]==dist[x]+1)
                parent[u].push_back(x);
        }
    }
}
void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[],int node){
    if(node==-1){
        Paths.push_back(path);
        return ;
    }
    for(auto u:parent[node]){
        path.push_back(u);
        shortestPaths(Paths,path,parent,u);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n=wordList.size(),sr=-1,ds=-1;
    vector<vector<string>> ANS;
    for(int i=0;i<n;i++){
        if(wordList[i]==beginWord)
            sr=i;
        if(wordList[i]==endWord)
            ds=i;
    }
    if(ds==-1)
        return ANS;
    if(sr==-1){
        wordList.emplace(wordList.begin(),beginWord);
        sr=0;
        ds++;
        n++;
    }
    vector <vector<int>> g(n,vector<int>()),Paths;
    vector <int> parent[n],path;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(able(wordList[i],wordList[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
    bfs(g,parent,n,sr,ds); 
    shortestPaths(Paths,path,parent,ds);
    for(auto u:Paths){
        vector <string> now;
        for(int i=0;i<u.size()-1;i++)
            now.push_back(wordList[u[i]]);
        reverse(now.begin(),now.end());
        now.push_back(wordList[ds]);
        ANS.push_back(now);
    }
    return ANS;
}
}; 
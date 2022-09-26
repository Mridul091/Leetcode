class Solution {
private:
    int fa[30];
public:
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void Union(int p, int q){
        int fp = find(p);
        int fq = find(q);
        if(fp != fq){
            fa[fp] = fq;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> v;
        for(int i = 0; i < 26; i++){
            fa[i] = i;
        }
        int n = equations.size();
        for(int i = 0; i < n; i++){
            if(equations[i][1] == '='){
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                Union(x,y);
            }else{
                v.push_back(i);
            }
        }
        for(int i = 0; i < v.size(); i++){
            int x = equations[v[i]][0] - 'a';
            int y = equations[v[i]][3] - 'a';
            if(find(x) == find(y)){
                return false;
            }
        }
        return true;
    }
};
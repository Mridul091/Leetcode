class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;
        sort(matches.begin(),matches.end());
        for(auto c:matches)
        {
            int x=c[0];
            int y=c[1];
            if(m.find(x)==m.end())
            {
                m[x]=0;
            }
            m[y]++;
        }
        vector<vector<int>> ans;
        vector<int> zero;
        vector<int> one;
        for(auto x:m)
        {
            if(x.second==0)
            zero.push_back(x.first);
            else if(x.second==1)
            one.push_back(x.first);
        }
       ans.push_back(zero);
       ans.push_back(one);
       return ans;
        
    }
};
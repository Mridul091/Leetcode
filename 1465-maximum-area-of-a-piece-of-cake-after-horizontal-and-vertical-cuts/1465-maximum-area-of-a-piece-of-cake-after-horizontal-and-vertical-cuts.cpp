class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& vert) {
        int mod = 1e9 + 7;
        
        hor.push_back(h);
        vert.push_back(w);
        hor.push_back(0);
        vert.push_back(0);
        int v_size = vert.size();
        int h_size = hor.size();
        sort(hor.begin(),hor.end());
        sort(vert.begin(),vert.end());
        int maxw = 0;
        int maxh = 0;
        for(int i=v_size-1;i>=1;i--){
            maxw = max(maxw, vert[i]-vert[i-1]);
        }
        for(int i=h_size-1;i>=1;i--){
            maxh = max(maxh, hor[i]-hor[i-1]);
        }
        return (long long)maxh*maxw%mod;
    }
};
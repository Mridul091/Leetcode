class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int res = INT_MAX;
        
        for(int i=1;i<=6;i++){
            int count=0;
            int cnt1=0;
            int cnt2=0;
            for(int j=0;j<n;j++){
                if(tops[j]==i||bottoms[j]==i){
                    count++;
                    if(tops[j]!=i)
                        cnt1++;
                    else if(bottoms[j]!=i)
                        cnt2++;
                }
           
            }
            if(count==n)
                res = min(res,min(cnt1,cnt2));
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};
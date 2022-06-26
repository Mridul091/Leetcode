class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

  
//         while(k){
//             if(cardPoints[i]>= cardPoints[j]){
//                 sum += cardPoints[i];
//             }
//             else{
//                 sum += cardPoints[j];
                
//             }
//             i++;
//             j--;
//             k--;
//             cout << sum << " ";
//         }
        vector<int> pre(n+1,0);
        vector<int> suf(n+1,0);
        
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1] + cardPoints[i-1];
            suf[i] = suf[i-1] + cardPoints[n-i];
        }
        
        int maxi = -1e9;
        int l,h;
        
        for(l=k,h=0;l>=0;l--,h++){
            maxi = max(maxi, pre[l] + suf[h]);
        }
        
        return maxi;
    }
};
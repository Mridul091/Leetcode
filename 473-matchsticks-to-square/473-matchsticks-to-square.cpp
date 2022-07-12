class Solution {
public:
    bool vis[16];

//     bool helper(vector<int> arr,int onesidelen, int totalside, int sum , int idx = 0){
        
//         if(totalside==1) return true;
//         if(sum==onesidelen) return helper(arr,onesidelen, totalside-1, 0, 0);
//         if(idx>=size(arr)) return false;
//         for(int i= idx;i<size(arr);i++){
//             if(!vis[i]){
//                 if(sum+arr[i] <= onesidelen){
//                     vis[i] = true;
//                     if(helper(arr,onesidelen, totalside, sum + arr[i], i+1)) return true;
//                     vis[i] = false;
//                 }
//             }
//         }
    
//         return false;

//     }
    
//     bool makesquare(vector<int>& matchsticks) {
//         memset(vis, false, sizeof(vis));
//         sort(matchsticks.rbegin(),matchsticks.rend());
//         int n = matchsticks.size();
//         if(n<4) return false;
//         int sum = 0;
//         for(auto it:matchsticks)
//             sum += it;
        
//         if( sum%4!=0) return false;
//         int oneside = sum/4;
//         return helper(matchsticks,oneside, 4, 0);
//     }
// };
bool canMakeSquare(vector < int > & matchsticks, int currentSum, int oneSideLength, int totalSides, int idx = 0) {
        if (totalSides == 1) // This is the optimisation
            return true;
        if (currentSum == oneSideLength)
            return canMakeSquare(matchsticks, 0, oneSideLength, totalSides - 1, 0);
        if (idx >= size(matchsticks))
            return false;
        for (int i = idx; i < size(matchsticks); i++) {
            if (!vis[i]) {
                if (currentSum + matchsticks[i] <= oneSideLength) {
                    vis[i] = true;
                    if (canMakeSquare(matchsticks, currentSum + matchsticks[i], oneSideLength, totalSides, i + 1))
                        return true;
                    vis[i] = false;
                }
            }
        }
        return false;
    }
 bool makesquare(vector < int > & matchsticks) {
        sort(matchsticks.rbegin(),matchsticks.rend());
        memset(vis, false, sizeof(vis));
        int sum = 0;
        for (int i: matchsticks)
            sum += i;
        if (sum % 4)
            return false;
        int oneSideLength = sum / 4;
        int totalSides = 4;
        return canMakeSquare(matchsticks, 0, oneSideLength, totalSides);

    }
};
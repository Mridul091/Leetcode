class Solution {
public:
     int paint_next_house(int i, int prev_col, int ngrh, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, vector<vector<vector<int>>>& dp){
        
        if(ngrh > target) return 1e9; //neighborhood more than req
        
        if(i == m){
            return ngrh == target ? 0 : 1e9; 
        }
        
        if(dp[i][prev_col][ngrh] != -1) return dp[i][prev_col][ngrh];
        
        int ans = 1e9; //INT_MAX may overflow
        
        if(houses[i] == 0){ //house needs to be coloured
            
            for(int j=0; j<n; j++){
                
                ans = min(ans, cost[i][j] +  // col, if new col diff than prev +1 in ngrhood
                          paint_next_house(i+1, j+1, prev_col==j+1 ? ngrh : ngrh+1, houses, cost, m, n, target, dp)); 
                
            }
        }
        
        else{
            
            ans = min(ans, paint_next_house(i+1, houses[i], prev_col==houses[i] ? ngrh : ngrh+1, houses, cost, m, n, target, dp));
            
        }
        
        return dp[i][prev_col][ngrh] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m+1,    
        vector<vector<int>>(n+1, vector<int>(target+1, -1)));
                                // first house, prev col null, 0 nghrhood
        int min_cost = paint_next_house(0, 0, 0, houses, cost, m, n , target, dp);
        if(min_cost >= 1e9) return -1;
        return min_cost;
    }
};


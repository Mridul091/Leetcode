class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(2,0), curr(2,0);
        prev[0] = prev[1] = 0;
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit = 0;
                if(j==1)
                    profit = max((-prices[i] + prev[0]), 0 + prev[1]);
                else
                    profit = max((prices[i] + prev[1]), 0 + prev[0]);
                
                curr[j] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};
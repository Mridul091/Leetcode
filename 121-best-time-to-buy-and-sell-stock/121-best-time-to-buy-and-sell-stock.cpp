class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_max = 0;
        int mini = 1e9;
        
        for(int i= 0;i<prices.size();i++){
            mini = min(prices[i], mini);
            profit_max = max(profit_max, prices[i]-mini);
        }
        return profit_max;
    }
};
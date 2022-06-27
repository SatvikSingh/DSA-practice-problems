class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), buy = 0, sell = -prices[0];
        
        for (int i = 1; i < n; i++) {
            buy = max(buy, sell + prices[i] - fee);
            sell = max(sell, buy - prices[i]);
        }
        
        return buy;
    }
};
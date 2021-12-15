class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), min_ele = prices[0], profit = 0;
        
        for (int i = 0; i < n; i++) {
            min_ele = min(prices[i], min_ele);
            profit = max(profit, (prices[i] - min_ele));
        }
        
        return profit;
    }
};
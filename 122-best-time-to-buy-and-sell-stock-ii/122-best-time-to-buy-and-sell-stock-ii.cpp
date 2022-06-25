class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), min_price = prices[0], profit = INT_MIN, ans = 0;
        
        for (int i = 0; i < n; i++) {
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
            if (profit > 0) {
                min_price = prices[i];
                ans += profit;
                profit = 0;
            }
        }
        
        return ans;
    }
};
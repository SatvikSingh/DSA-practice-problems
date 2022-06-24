class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = INT_MIN, buy_price = prices[0];
        
        for (int i = 0; i < n; i++) {
            buy_price = min(buy_price, prices[i]);
            ans = max(ans, (prices[i] - buy_price));
        }
        
        return ans;
    }
};
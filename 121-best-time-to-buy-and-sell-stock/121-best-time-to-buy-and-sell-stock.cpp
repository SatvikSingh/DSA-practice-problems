class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_day = 0, sell_day = 0, n = prices.size();
        int curr_max_profit = 0, max_profit = INT_MIN;
        
        while (sell_day < n) {
            int sell_price = prices[sell_day];
            int buy_price = prices[buy_day];
            
            if (sell_price < buy_price) {
                buy_day = sell_day;
                sell_day++;
            }
            else {
                curr_max_profit = sell_price - buy_price;
                max_profit = max(max_profit, curr_max_profit);
                sell_day++;
            }
        }
        
        return max_profit;
    }
};
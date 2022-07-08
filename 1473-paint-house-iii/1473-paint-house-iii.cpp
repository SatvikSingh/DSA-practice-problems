class Solution {
public:
    const int MAX = 1000001;
    
    int helper(vector<int> &houses, vector<vector<int>> &cost, int target, int curr, int neighbor, int prev, vector<vector<vector<int>>> &dp, int m , int n) {
        if (curr == m) {
            if (neighbor == target)
                return 0;
            else
                return MAX;
        }
        
        if (neighbor > target)
            return MAX;
        
        if (dp[curr][neighbor][prev] != -1)
            return dp[curr][neighbor][prev];
        
        int min_cost = MAX;
        
        if (houses[curr]) {
            int new_neighbor = 0;
            
            if (houses[curr] == prev or prev == 0)
                new_neighbor = neighbor;
            else
                new_neighbor = neighbor + 1;
            
            // cout << houses[curr] << " " << prev << endl;
            
            min_cost = helper(houses, cost, target, curr+1, new_neighbor, houses[curr], dp, m, n);
        }
        else {
            for (int i = 1; i <= n; i++) {
                int new_neighbor = 0;
            
                if (i == prev or prev == 0)
                    new_neighbor = neighbor;
                else
                    new_neighbor = neighbor + 1;
                
                
                int curr_cost = cost[curr][i-1] + helper(houses, cost, target, curr+1, new_neighbor, i, dp, m, n);
                min_cost = min(min_cost, curr_cost);
            }
        }
        
        dp[curr][neighbor][prev] = min_cost;
        
        return min_cost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // int n = houses.size();
        vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(21, -1)));
        
        int ans = helper(houses, cost, target, 0, 1, 0, dp, m, n);
        
        if (ans == MAX)
            return -1;
        else
            return ans;
        
    }
};
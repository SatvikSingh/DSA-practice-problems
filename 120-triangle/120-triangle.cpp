class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i+1, 0);
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j];
            }
        }
        
        if (n == 1) {
            return dp[0][0];
        }
        
        dp[1][0] += dp[0][0];
        dp[1][1] += dp[0][0];
        
        if (n == 2) {
            return min(dp[1][0], dp[1][1]);
        }
        
        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    dp[i][j] += dp[i-1][j];
                else if (j == i)
                    dp[i][j] += dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j] + dp[i-1][j-1], dp[i][j] + dp[i-1][j]);
            }
        }
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= i; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
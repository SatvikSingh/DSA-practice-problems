class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    for (int x = 0; x <= min(j, i-1); x++) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % 1000000007;
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};
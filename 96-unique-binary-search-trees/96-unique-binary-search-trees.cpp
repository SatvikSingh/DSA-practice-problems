class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i < j; i++) {
                dp[j] += dp[i] * dp[j-i-1];
            }
        }
        
        return dp[n];
    }
};
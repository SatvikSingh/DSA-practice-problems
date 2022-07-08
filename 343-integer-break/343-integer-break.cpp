class Solution {
public:
    int helper(int n, int i, vector<vector<int>> &dp) {
        if (i == 0 or n == 0)
            return 1;
        
        if (dp[n][i] != -1)
            return dp[n][i];
        
        if (i > n) 
            return dp[n][i] = helper(n, i-1, dp);
        else
            return dp[n][i] = max(helper(n, i-1, dp), i*helper(n-i, i, dp));
    }
    
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(n, n-1, dp);    
    }
};
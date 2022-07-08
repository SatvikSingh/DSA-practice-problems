class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        int digit = 1;
        
        while (digit*digit <= n) {
            int square = digit*digit;
            for (int i = square; i <= n; i++) {
                dp[i] = min(dp[i-square]+1, dp[i]);
            } 
            digit++;
        }
        
        return dp.back();
    }
};
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        if (n == 0) {
            return 0;
        }
        
        dp[n] = 1;
        
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] = dp[i+1];
                if (i < n-1 and (s[i] == '1' or (s[i] == '2' and s[i+1] < '7'))) {
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
    }
};
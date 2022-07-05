class Solution {
public:
    int helper(string &s, int start, int end, vector<vector<int>> &dp) {
        // int ans = 0;
        
        if (start == end) 
            return 1;
        if (start > end)
            return 0;
        
        if (dp[start][end] != 0)
            return dp[start][end];
        
        if (s[start] == s[end]) {
            dp[start][end] = 2 + helper(s, start+1, end-1, dp);
        }
        else {
            dp[start][end] = max(helper(s, start+1, end, dp), helper(s, start, end-1, dp));
        }
        
        return dp[start][end];
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return helper(s, 0, n-1, dp);
    }
};
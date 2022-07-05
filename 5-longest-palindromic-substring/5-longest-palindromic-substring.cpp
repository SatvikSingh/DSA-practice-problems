class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = 1; i <= n-1; i++) {
            if (s[i] == s[i-1]) {
                dp[i-1][i] = 2;
            }
        }
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = n-1; j >= i+2; j--) {
                if (s[i] == s[j]) {
                    if (dp[i+1][j-1] != 0) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }
            }
        }
        
        int start = 0, max_ele = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > max_ele) {
                    max_ele = dp[i][j];
                    start = i;
                }
            }
        }
        
        // cout << start << " " << max_ele << endl;
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        return s.substr(start, max_ele);
    }
};
class Solution {
public:
    int dp[21][31];
    bool check(string s, string p, int i, int j) {
        if (j == p.length()) {
            if (i == s.length())
                return true;
            else
                return false;
        }
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        bool first_match = i < s.length() and (s[i] == p[j] or p[j] == '.');
        
        if (j+1 < p.length() and p[j+1] == '*') {
            return dp[i][j] = (check(s, p, i, j+2) or (first_match and check(s, p, i+1, j)));
        }
        else {
            return dp[i][j] = (first_match and check(s, p, i+1, j+1));
        }
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return check(s, p, 0, 0);
    }
};
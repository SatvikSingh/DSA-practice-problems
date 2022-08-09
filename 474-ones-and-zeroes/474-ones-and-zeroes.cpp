class Solution {
public:
    int dp[601][101][101];
    int helper(vector<pair<int, int>>& temp, int i, int m, int n) {
        if (i == temp.size() or (m == 0 and n == 0))
            return 0;
        
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        
        if (temp[i].first > m or temp[i].second > n)
            return dp[i][m][n] = helper(temp, i+1, m, n);
        
        return dp[i][m][n] = max(helper(temp, i+1, m-temp[i].first, n-temp[i].second)+1, helper(temp, i+1, m, n));
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> temp;
        memset(dp, -1, sizeof(dp));
        
        for (auto s : strs) {
            int ones = 0, zeroes = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '0')
                    zeroes++;
                else
                    ones++;
            }
            temp.push_back({zeroes, ones});
        }
        
        return helper(temp, 0, m, n);
    }
};
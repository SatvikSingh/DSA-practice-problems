class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0)); 
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i-1][j-1] - dp[i-1][j-1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r1 = max(0, i-k)+1;
                int c1 = max(0, j-k)+1;
                
                int r2 = min(i+k+1, n);
                int c2 = min(j+k+1, m);
                
                ans[i][j] = dp[r2][c2] + dp[r1-1][c1-1] - dp[r1-1][c2] - dp[r2][c1-1];
            }
        }
        
        return ans;
    }
};
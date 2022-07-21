class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        // cout << sum << endl;
        
        if (sum % 2 == 1) {
            return false;
        }
        
        sum /= 2;
        
        vector<vector<bool>> dp(sum+1, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = true;
        }
        
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j-1];
                if (i - nums[j-1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
            }
        }
        
        return dp[sum][n-1];
    }
};
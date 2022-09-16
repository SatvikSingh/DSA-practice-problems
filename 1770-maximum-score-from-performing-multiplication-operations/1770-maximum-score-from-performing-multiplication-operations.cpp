class Solution {
public:
    int helper(vector<int>& nums, vector<int>& multipliers, int idx, int i, int j, vector<vector<int>>& dp) {
        if (idx >= multipliers.size())
            return 0;
        
        if (dp[idx][i] != INT_MIN)
            return dp[idx][i];
        
        int take_from_start = nums[i] * multipliers[idx] + helper(nums, multipliers, idx+1, i+1, j, dp);
        int take_from_end = nums[(nums.size()-1) - (idx - i)] * multipliers[idx] + helper(nums, multipliers, idx+1, i, j-1, dp);
        
        return dp[idx][i] = max(take_from_start, take_from_end);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size(), n = nums.size();
        int i = 0, j = nums.size()-1;
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        
        return helper(nums, multipliers, 0, i, j, dp);
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};
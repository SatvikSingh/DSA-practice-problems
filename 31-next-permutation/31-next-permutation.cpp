class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), breakpoint = -1;
        
        for (int i = n-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                breakpoint = i-1;
                break;
            }
        }
        
        if (breakpoint == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for (int i = n-1; i > 0; i--) {
            if (nums[i] > nums[breakpoint]) {
                swap(nums[i], nums[breakpoint]);
                reverse(nums.begin() + breakpoint + 1, nums.end());
                break;
            }
        }
    }
};
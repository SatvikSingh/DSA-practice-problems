class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), count = 0, idx = 0;
        
        if (n < 3)
            return 0;
        
        int diff = nums[1] - nums[0];
        
        for (int i = 1; i < n-1; i++) {
            int curr_diff = nums[i+1] - nums[i];
            if (curr_diff == diff) {
                idx++;
            }
            else {
                diff = curr_diff;
                idx = 0;
            }
            
            count += idx;
        }
        
        return count;
    }
};
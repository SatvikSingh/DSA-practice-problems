class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), count = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) {
                count++;
            }
            else {
                int temp = count;
                if (temp == 0) {
                    return nums[i];
                }
                count = 0;
            }
        }
        
        return nums.back();
    }
};
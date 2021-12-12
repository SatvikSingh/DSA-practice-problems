class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[j] == target - nums[i]) {
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};
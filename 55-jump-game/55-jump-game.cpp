class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), jump = 0, i = 0;
        
        for (i = 0; i < n and i <= jump; i++) {
            jump = max(i + nums[i], jump);
        }
        
        return i == n;
    }
};
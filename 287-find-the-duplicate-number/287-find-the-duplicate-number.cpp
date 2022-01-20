class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans;
        
        int slow = nums[0], fast = nums[0];
        
        do {
            slow = nums[nums[slow]];
            fast = nums[fast];
        }
        while (slow != fast);
        
        fast = nums[0];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
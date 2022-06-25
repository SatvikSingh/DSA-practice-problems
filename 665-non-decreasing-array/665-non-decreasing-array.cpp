class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1]) {
                if (i-1 >= 0 and nums[i-1] > nums[i+1])
                    nums[i+1] = nums[i];
                else 
                    nums[i] = nums[i+1];
                break;
            }
        }
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1])
                return false;
        }
        
        return true;
    }
};
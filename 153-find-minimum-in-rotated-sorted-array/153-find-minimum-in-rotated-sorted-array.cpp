class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        
        if (nums[start] < nums[end])
            return nums[0];
        
        while (end - start > 1) {
            int mid = (start + end)/2;
            
            if (nums[mid] > nums[start]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        
        return nums[end];
    }
};
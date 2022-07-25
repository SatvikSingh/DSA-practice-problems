class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n-1, first = -1, last = -1;
        
        while (start <= end) {
            int mid = (start+end)/2;
            
            if (nums[mid] > target) {
                end = mid-1;
            }
            else if (nums[mid] < target) {
                start = mid+1;
            }
            else {
                if (mid == 0 or nums[mid] != nums[mid-1]) {
                    first = mid;
                    break;
                }
                else {
                    end = mid-1;
                    first = mid-1;
                }
            }
        }
        
        start = 0, end = n-1;
        
        while (start <= end) {
            int mid = (start+end)/2;
            
            if (nums[mid] > target) {
                end = mid-1;
            }
            else if (nums[mid] < target) {
                start = mid+1;
            }
            else {
                if (mid == n-1 or nums[mid] != nums[mid+1]) {
                    last = mid;
                    break;
                }
                else {
                    start = mid+1;
                    last = mid+1;
                }
            }
        }
        
        return {first, last};
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while (start <= end) {
            int mid = (start+end)/2;
            
            if (target == nums[mid])
                return mid;
            
            if (nums[start] <= nums[mid]) {      // we are in the left portion
                if (target > nums[mid] or target < nums[start])
                    start = mid+1;
                else 
                    end = mid-1;
            }
            else {      // we are in the right portion
                if (target < nums[mid] or target > nums[end]) 
                    end = mid-1;
                else
                    start = mid+1;
            }
        }
        
        return -1;
    }
};
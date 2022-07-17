class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1, start = 0, mid;
        
         while (start <= end) {
             mid = (start+end)/2;
             
             if (nums[mid] == target) 
                 return mid;
             
             if (nums[start] <= nums[mid]) {
                 if (nums[start] <= target and nums[mid] >= target)
                     end = mid-1;
                 else
                     start = mid+1;
             }
             else {
                 if (nums[end] >= target and nums[mid] <= target)
                     start = mid+1;
                 else
                     end = mid-1;
             }
         }
        
        return -1;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        while (start < end) {
            int mid = (start+end)/2;
            
            if (nums[mid] > nums[mid+1])
                end = mid;
            else
                start = mid+1;
        }
        
        return start;
    }
};
class Solution {
public:
    void merge(vector<int>& nums, int start, int end, int mid) {
        int i = start, j = mid+1, k = 0;
        vector<int> temp(end-start+1);
        while (i <= mid and j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                k++;
                i++;
            }
            else {
                temp[k] = nums[j];
                k++;
                j++;
            }
        }
        while (i <= mid) {
            temp[k] = nums[i];
            k++; i++;
        }
        while (j <= end) {
            temp[k] = nums[j];
            k++; j++;
        }
        for (i = 0; i < k; i++) {
            nums[start+i] = temp[i];
        }
    }
    
    void sort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        int mid = (start+end)/2;
        sort(nums, start, mid);
        sort(nums, mid+1, end);
        merge(nums, start, end, mid);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};
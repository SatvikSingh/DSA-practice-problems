class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int prod = 1, count = 0;
        
        if (k == 0 or k == 1)
            return 0;
        
        for (int j = 0; j < n; j++) {
            prod = prod*nums[j];
            
            while (prod >= k) {
                prod = prod/nums[i];
                i++;
            }
            
            count += j-i+1;
        }
        
        return count;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map{{0, 0}};
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (!map.count(sum % k))
                map[sum % k] = i+1;
            else if (map[sum % k] < i)
                return true;
        }
        
        return false;
    }
};
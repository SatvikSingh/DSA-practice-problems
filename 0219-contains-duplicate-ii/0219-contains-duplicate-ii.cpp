class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> map;
        
        for (int i = 0; i < n; i++) {
            if (map.count(nums[i]))
                if (i - map[nums[i]] <= k)
                    return true;
            
            map[nums[i]] = i;
        }
        
        return false;
    }
};
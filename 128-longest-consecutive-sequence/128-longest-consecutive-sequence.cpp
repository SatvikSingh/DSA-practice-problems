class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), count = 0;
        set<int> set;
        
        if (n == 0)
            return 0;
        
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }
        
        for (auto i : set) {
            if (!set.count(i-1)) {
                int len = 1;
                while (set.count(i + len))
                    len++;
                
                count = max(count, len);
            }
        }
        
        return count;
    }
};
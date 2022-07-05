class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), count = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for (auto i : s) {
            int curr = 1;
            for (int j = 1; s.count(i-j); j++) {
                s.erase(i-j);
                curr++;
            }
            for (int j = 1; s.count(i+j); j++) {
                s.erase(i+j);
                curr++;
            }
            count = max(count, curr);
        }
        
        return count;
    }
};
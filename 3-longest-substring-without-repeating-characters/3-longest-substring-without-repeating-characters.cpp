class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();
        unordered_set<int> set;
        int curr_size = 0, max_size = 0;
        
        while (r < n) {
            if (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            else {
                set.insert(s[r]);
                // curr_size++;
                max_size = max(max_size, r-l+1);
                r++;
            }
        }
        
        return max_size;
    }
};
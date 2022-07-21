class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0, ans = 0, n = s.length();
        
        while (right < n) {
            map[s[right]]++;
            while (map[s[right]] > 1) {
                map[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};
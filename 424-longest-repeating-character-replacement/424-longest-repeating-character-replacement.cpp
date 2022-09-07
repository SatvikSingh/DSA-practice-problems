class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, l = 0, r = 0, n = s.length(), max_count = 0;
        unordered_map<char, int> map;
        
        while (r < n) {
            map[s[r]]++;
            
            max_count = max(max_count, map[s[r]]);
            
            if (r - l + 1 - max_count > k) {
                map[s[l]]--;
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};
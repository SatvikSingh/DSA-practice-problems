class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        
        if (s.size() != t.size()) {
            return false;
        }
        
        for (int i = 0; i < t.length(); i++) {
            map[t[i]]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]--;
            if (map[s[i]] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
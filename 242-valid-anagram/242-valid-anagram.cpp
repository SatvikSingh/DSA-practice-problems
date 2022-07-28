class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        
        if (s.length() != t.length())
            return false;
        
        for (auto c : s) {
            map[c]++;
        }
        
        for (auto c : t) {
            map[c]--;
            if (map[c] < 0)
                return false;
        }
        
        return true;
    }
};
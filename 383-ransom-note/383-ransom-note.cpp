class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        
        for (auto c : magazine) {
            map[c]++;
        }
        
        for (auto c : ransomNote) {
            if (map[c] > 0) {
                map[c]--;
            }
            else {
                return false;
            }
        }
        
        return true;
    }
};
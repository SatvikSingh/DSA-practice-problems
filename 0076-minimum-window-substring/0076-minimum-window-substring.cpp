class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        
        for (auto c : t) {
            map[c]++;
        }
        
        int i = 0, j = 0, count = t.length();
        int min_start = 0, min_len = INT_MAX;
        
        while (j < s.length()) {
            if (map[s[j]] > 0)
                count--;
            
            map[s[j]]--;
            j++;
            
            while (count == 0) {
                if (j-i < min_len) {
                    min_start = i;
                    min_len = j-i;
                } 
                
                map[s[i]]++;
                
                if (map[s[i]] > 0)
                    count++;
                
                i++;
            }
        }
        
        if (min_len == INT_MAX)
            return "";
        else
            return s.substr(min_start, min_len);
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size(), count = 0, same_letter = 0;
        unordered_map<string, int> map;
        
        for (auto s : words) {
            if (s[0] == s[1]) {
                if (map[s] > 0) {
                    same_letter--;
                    map[s]--;
                    count += 4;
                }
                else {
                    map[s]++;
                    same_letter++;
                }
            }   
            else {
                string temp = s;
                reverse(temp.begin(), temp.end());
                
                if (map[temp] > 0) {
                    map[temp]--;
                    count += 4;
                }
                else {
                    map[s]++;
                }
            }
        }
        
        if (same_letter > 0)
            count += 2;
        
        return count;
    }
};
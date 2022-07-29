class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        vector<string> ans;
        int flag = 0;
        
        for (auto word : words) {
            int n = word.length();
        
            for (int i = 0; i < n; i++) {
                if ((map1.count(word[i]) and map1[word[i]] != pattern[i]) or (map2.count(pattern[i]) and map2[pattern[i]] != word[i]))
                    flag = 1;
                else {
                    map1[word[i]] = pattern[i];
                    map2[pattern[i]] = word[i];
                }
            }
            if (flag == 0) {
                ans.push_back(word);
            }
            flag = 0;
            map1.clear();
            map2.clear();
        }
        
        return ans;
    }
};
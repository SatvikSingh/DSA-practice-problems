class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        string temp = "";
        
        for (auto s : strs) {
            vector<int> ch(26, 0);
            for (auto c : s) {
                ch[c - 'a']++;
            }
            
            for (auto i : ch) {
                temp += i + 'a';
            }
            
            // cout << temp << endl;
            
            map[temp].push_back(s);
            temp.clear();
            // ch.clear();
        }
        
        for (auto i : map) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
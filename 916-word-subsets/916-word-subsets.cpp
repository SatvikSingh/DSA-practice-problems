class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> map;
        
        for (auto word : words2) {
            unordered_map<char, int> temp;
            
            for (auto c : word) {
                temp[c]++;
                if (temp[c] > map[c])
                    map[c]++;
            }
        }
        
        for (auto word : words1) {
            unordered_map<char, int> temp;
            
            for (auto c : word) {
                temp[c]++;
            }
            
            int flag = 0;
            
            for (auto i : map) {
                if (i.second > temp[i.first]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0)
                ans.push_back(word);
        }
        
        return ans;
    }
};
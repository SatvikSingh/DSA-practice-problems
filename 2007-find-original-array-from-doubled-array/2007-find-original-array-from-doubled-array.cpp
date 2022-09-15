class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        unordered_map<int, int> map;
        
        sort(changed.begin(), changed.end());
        
        if (changed.size() % 2 == 1)
            return {};
        
        for (auto i : changed) {
            map[i]++;
        }
        
        for (auto i : changed) {
            if (map[i] == 0)
                continue;
            
            if (map[2*i] == 0)
                return {};
            
            ans.push_back(i);
            
            map[i]--;
            map[2*i]--;
        }
        
        return ans;
    }
};
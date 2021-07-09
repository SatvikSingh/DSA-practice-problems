class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> map;
        
        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
            if (map[arr[i]].size() == arr[i]) {
                ans.push_back(map[arr[i]]);
                map[arr[i]].clear();
            }
        }
        return ans;
    }
};
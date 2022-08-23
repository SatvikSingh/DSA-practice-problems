class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> map;
        vector<vector<int>> bucket(n+1);
        
        for (auto i : nums)
            map[i]++;
        
        for (auto i : map)
            bucket[i.second].push_back(i.first);
        
        for (int i = n; i >= 0; i--) {
            if (ans.size() == k)
                break;
            
            if (!bucket[i].empty()) {
                for (auto j : bucket[i])
                    ans.push_back(j);
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> pq;
        
        for (auto i : nums)
            map[i]++;
        
        for (auto i : map)
            pq.push({i.second, i.first});
        
        while (k > 0) {
            int temp = pq.top().second;
            pq.pop();
            ans.push_back(temp);
            k--;
        }
        
        return ans;
    }
};
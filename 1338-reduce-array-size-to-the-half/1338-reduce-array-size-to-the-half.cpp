class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        priority_queue<int> pq;
        int n = arr.size(), count = 0, deleted = 0;
        
        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
        }
        
        for (auto i : map) {
            pq.push(i.second);
        }
        
        while (true) {
            deleted += pq.top();
            pq.pop();
            count++;
            
            if (deleted >= n/2)
                return count;
        }
        
        return 0;
    }
};
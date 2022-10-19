class Solution {
public:
    class compare {
        public:
        bool operator() (pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
        
            return a.first < b.first;
        }   
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<int, string>> helper;
        map<string, int> map;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        
        for (auto s : words) {
            map[s]++;
        }
        
        for (auto i : map) {
            pq.push({i.second, i.first});
        }
        
        int temp1 = k;
        
        while (k > 0) {
            auto temp = pq.top();
            string s = temp.second;
            int freq = temp.first;
            pq.pop();
            ans.push_back(s);
            k--;
        }
        
        return ans;
    }
};
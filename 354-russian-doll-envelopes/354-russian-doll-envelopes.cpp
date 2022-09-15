class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> temp;
        
        for (int i = 0; i < n; i++) {
            int curr_w = envelopes[i][1];
            
            int idx = lower_bound(temp.begin(), temp.end(), curr_w) - temp.begin();
            
            if (idx == temp.size())
                temp.push_back(curr_w);
            else
                temp[idx] = curr_w;
        }
        
        return temp.size();
    }
};
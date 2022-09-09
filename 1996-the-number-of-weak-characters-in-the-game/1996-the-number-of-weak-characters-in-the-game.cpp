class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        
        return a[0] < b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size(), count = 0, curr = INT_MIN;
        
        sort(properties.begin(), properties.end(), compare);
        
        for (int i = n-1; i >= 0; i--) {
            if (properties[i][1] < curr) {
                count++;
            }
            
            curr = max(curr, properties[i][1]);
        }
        
        return count;
    }
};
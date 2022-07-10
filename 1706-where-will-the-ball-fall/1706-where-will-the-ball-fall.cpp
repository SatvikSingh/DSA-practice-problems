class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            int pos1 = i, pos2;
            for (int j = 0; j < m; j++) {
                pos2 = pos1 + grid[j][pos1];
                if (pos2 < 0 or pos2 >= n or grid[j][pos2] != grid[j][pos1]) {
                    pos1 = -1;
                    break;
                }
                pos1 = pos2;
            }
            ans.push_back(pos1);
        }
        
        return ans;
    }
};
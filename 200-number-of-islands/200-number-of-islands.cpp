class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 or j < 0 or i >= n or j >= m) {
            return;
        }    
        
        if (grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        helper(grid, i-1, j, n, m);
        helper(grid, i+1, j, n, m);
        helper(grid, i, j-1, n, m);
        helper(grid, i, j+1, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    helper(grid, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};
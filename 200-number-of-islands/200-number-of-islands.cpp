class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int n, int m) {
        if (row < 0 or col < 0 or row >= n or col >= m or grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        
        dfs(grid, row+1, col, n, m);
        dfs(grid, row-1, col, n, m);
        dfs(grid, row, col+1, n, m);
        dfs(grid, row, col-1, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};
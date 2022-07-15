class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid, int n, int m) {
        if (row < 0 or row >= n or col < 0 or col >= m or visited[row][col] == 1 or grid[row][col] == 0) {
            return 0;
        }
        
        visited[row][col] = 1;
        
        int ans = (1 + helper(row+1, col, visited, grid, n, m) + helper(row-1, col, visited, grid, n, m) + helper(row, col+1, visited, grid, n, m) + helper(row, col-1, visited, grid, n, m));
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, helper(i, j, visited, grid, n, m));
            }
        }
        
        return ans;
    }
};
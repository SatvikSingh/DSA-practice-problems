class Solution {
public:
    void helper(vector<vector<int>>& heights, vector<vector<int>>& visited, vector<vector<int>>& pacific, vector<vector<int>>& atlantic, vector<vector<int>>& ans, int row, int col, int n, int m) {
        if (visited[row][col] == 1)
            return;
        
        visited[row][col] = 1;
        
        if (pacific[row][col] == 1 and atlantic[row][col] == 1)
            ans.push_back({row, col});
        
        if (row > 0 and heights[row-1][col] >= heights[row][col])
            helper(heights, visited, pacific, atlantic, ans, row-1, col, n, m);
        
        if (row < n-1 and heights[row+1][col] >= heights[row][col])
            helper(heights, visited, pacific, atlantic, ans, row+1, col, n, m);
        
        if (col > 0 and heights[row][col-1] >= heights[row][col])
            helper(heights, visited, pacific, atlantic, ans, row, col-1, n, m);
        
        if (col < m-1 and heights[row][col+1] >= heights[row][col])
            helper(heights, visited, pacific, atlantic, ans, row, col+1, n, m);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific_visited(n, vector<int>(m, 0));
        vector<vector<int>> atlantic_visited(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            helper(heights, pacific_visited, pacific_visited, atlantic_visited, ans, i, 0, n, m);
            helper(heights, atlantic_visited, pacific_visited, atlantic_visited, ans, i, m-1, n, m);
        }
        
        for (int i = 0; i < m; i++) {
            helper(heights, pacific_visited, pacific_visited, atlantic_visited, ans, 0, i, n, m);
            helper(heights, atlantic_visited, pacific_visited, atlantic_visited, ans, n-1, i, n, m);
        }
        
        return ans;
    }
};
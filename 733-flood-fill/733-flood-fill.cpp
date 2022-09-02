class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int color, int new_color) {
        if (image[row][col] == new_color) {
            image[row][col] = color;
            if (row > 0)
                dfs(image, row-1, col, color, new_color);
            if (col > 0)
                dfs(image, row, col-1, color, new_color);
            if (row < image.size()-1)
                dfs(image, row+1, col, color, new_color);
            if (col < image[0].size()-1)
                dfs(image, row, col+1, color, new_color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int new_color = image[sr][sc];
        
        if (new_color != color)
            dfs(image, sr, sc, color, new_color);
        
        return image;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, grid[9][9] = {0};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '0';
                int k = (i/3)*3+(j/3);
                
                if (row[i][num-1] or col[j][num-1] or grid[k][num-1])
                    return false;
                
                row[i][num-1] = 1;
                col[j][num-1] = 1;
                grid[k][num-1] = 1;
            }
        }
        
        return true;
    }
};
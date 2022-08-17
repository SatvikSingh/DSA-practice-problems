class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 or j < 0 or i >= n or j >= m or board[i][j] != 'X')
            return;
        
        board[i][j] = 'v';
        
        helper(board, i+1, j, n, m);
        helper(board, i, j+1, n, m);
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    count++;
                    helper(board, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};
class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i < 0 or j < 0 or i >= n or j >= m or board[i][j] != 'O')
            return;
        
        board[i][j] = '$';
        
        helper(board, i+1, j, n, m);
        helper(board, i-1, j, n, m);
        helper(board, i, j-1, n, m);
        helper(board, i, j+1, n, m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O')
                helper(board, i, 0, n, m);
            if(board[i][m-1] == 'O')
                helper(board, i, m-1, n, m);
        }
        
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O')
                helper(board, 0, i, n, m);
            if(board[n-1][i] == 'O')
                helper(board, n-1, i, n, m);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }
};
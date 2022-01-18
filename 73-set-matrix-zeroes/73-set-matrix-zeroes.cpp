class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> row_arr(n, -1);
        vector<int> col_arr(m, -1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    col_arr[i] = 0;
                    row_arr[j] = 0;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (col_arr[i] == 0 or row_arr[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
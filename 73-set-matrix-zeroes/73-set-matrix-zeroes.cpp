class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), x = -1000000000000;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k1 = 0; k1 < n; k1++) {
                        if (matrix[i][k1] != 0) {
                            matrix[i][k1] = x;
                        }
                    }
                    for (int k2 = 0; k2 < m; k2++) {
                        if (matrix[k2][j] != 0) {
                            matrix[k2][j] = x;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == x) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
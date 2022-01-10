class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), depth = n/2;
        
        for (int i = 0; i < depth; i++) {
            int k = n-2*i-1, x = n-1-i;
            for (int j = 0; j < k; j++) {
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[x-j][i];
                matrix[x-j][i] = matrix[x][x-j];
                matrix[x][x-j] = matrix[i+j][x];
                matrix[i+j][x] = temp;
            }
        }
    }
};
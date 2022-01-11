class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int val = 1, dir = 1;
        
        while (top <= bottom and left <= right) {
            if (dir == 1) {
                for (int i = left; i <= right; i++) {
                    ans[top][i] = val;
                    val++;
                }
                top++;
                dir = 2;
            }
            else if (dir == 2) {
                for (int i = top; i <= bottom; i++) {
                    ans[i][right] = val;
                    val++;
                }
                right--;
                dir = 3;
            }
            else if (dir == 3) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = val;
                    val++;
                }
                bottom--;
                dir = 4;
            }
            else if (dir == 4) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = val;
                    val++;
                }
                left++;
                dir = 1;
            }
        }
        
        return ans;
    }
};
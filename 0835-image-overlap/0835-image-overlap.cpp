class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& img1, vector<vector<int>>& img2, int n) {
        int left = 0, right = 0;
        int img2_row = 0;

        for (int i = y; i < n; i++) {
            int img2_col = 0;
            
            for (int j = x; j < n; j++) {
                if (img1[i][j] == 1 and img1[i][j] == img2[img2_row][img2_col])
                    left++;
                if (img1[i][img2_col] == 1 and img1[i][img2_col] == img2[img2_row][j])
                    right++;
                
                img2_col++;
            }
            
            img2_row++;
        }
        
        return max(left, right);
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, helper(j, i, img1, img2, n));
                ans = max(ans, helper(j, i, img2, img1, n));
            }
        }
        
        return ans;
    }
};
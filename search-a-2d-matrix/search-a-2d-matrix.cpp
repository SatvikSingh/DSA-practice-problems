class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, l = 0, r = matrix.size()-1, mid;
        
        if (!matrix.size() or !matrix[0].size()) {
            return false;
        }
        
        //binary search 1 to find row which contains target
        
        while (l < r) {
            mid = (l+r)/2;
            if (matrix[mid].back() < target) {
                l = mid + 1;
            }
            else if (matrix[mid][0] > target) {
                r = mid - 1;
            }
            else {
                l = mid;
                break;
            }
        }
        
        row = l; //we found the row
        
        //binary search 2 to find the target inside the row we found
        
        l = 0;
        r = matrix[0].size()-1;
        
        while (l <= r) {
            mid = (l+r)/2;
            if (matrix[row][mid] < target) {
                l = mid + 1;
            }
            else if (matrix[row][mid] > target) {
                r = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
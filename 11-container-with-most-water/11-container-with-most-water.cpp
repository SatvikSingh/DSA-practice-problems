class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i = 0, j = n-1;
        int area = 0;
        
        while (i < j) {
            int curr_area = (j-i)*min(height[i], height[j]);
            
            if (height[i] < height[j])
                i++;
            else if (height[i] > height[j])
                j--;
            else {
                i++;
                j--;
            }
            
            if (curr_area > area) {
                area = curr_area;
            }
        }
        
        return area;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), max_area = INT_MIN;
        
        int i = 0, j = n-1;
        
        while (i < j) {
            int area = (j-i)*min(height[i], height[j]);
            
            if (height[i] > height[j])
                j--;
            else if (height[i] < height[j])
                i++;
            else {
                i++;
                j--;
            }
            
            max_area = max(area, max_area);
        }
        
        return max_area;
    }
};
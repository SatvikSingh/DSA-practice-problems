class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> dp_left(n, INT_MIN), dp_right(n, INT_MIN);
        
        if (n == 0)
            return 0;
        
        dp_left[0] = height[0];
        dp_right[n-1] = height[n-1];
        
        for (int i = 1; i < n; i++) {
            dp_left[i] = max(height[i], dp_left[i-1]);
        }
        
        for (int i = n-2; i >= 0; i--) {
            dp_right[i] = max(height[i], dp_right[i+1]);
        }
        
        for (int i = 1; i < n-1; i++) {
            ans = ans + min(dp_left[i], dp_right[i]) - height[i];
        }
        
        return ans;
    }
};
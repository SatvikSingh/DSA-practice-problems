class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int max_area = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int start = i;
            
            while (!st.empty() and st.top().second > heights[i]) {
            int idx = st.top().first, h = st.top().second;
                int temp_area = h*(i-idx);
                st.pop();
                
                max_area = max(max_area, temp_area);
                
                start = idx;
            }
            
            st.push({start, heights[i]});
        }
        
        while (!st.empty()) {
            int idx = st.top().first, h = st.top().second;
            int temp_area = h*(n-idx);
            
            st.pop();
            
            max_area = max(max_area, temp_area);
        }
        
        return max_area;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans;
        
        ans.push_back(0);
        st.push({temperatures.back(), n-1});
        
        for (int i = n-2; i >= 0; i--) {
            if (st.empty())
                st.push({temperatures[i], i});
            
            if (st.top().first > temperatures[i]) {
                ans.push_back(1);
            }
            else {
                while (!st.empty() and st.top().first <= temperatures[i]) {
                    st.pop();
                }
                
                if (st.empty())
                    ans.push_back(0);
                else
                    ans.push_back(abs(st.top().second - i));
            }
            
            st.push({temperatures[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
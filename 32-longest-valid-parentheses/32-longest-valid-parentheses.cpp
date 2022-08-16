class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        stack<int> st;
        st.push(-1);
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    ans = max(ans, i - st.top());
            }
        }
        
        return ans;
    }
};
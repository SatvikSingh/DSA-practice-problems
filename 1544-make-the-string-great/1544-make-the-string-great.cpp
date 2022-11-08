class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";
        
        for (auto c : s) {
            if (!st.empty()) {
                // cout << st.top() << " " << c << endl;
                if ((st.top() == tolower(st.top()) and c == toupper(c) and st.top() == tolower(c)) or (st.top() == toupper(st.top()) and c == tolower(c) and st.top() == toupper(c))) {
                    // cout << "asj" << endl;
                    st.pop();
                    continue;
                }
            }
            
            st.push(c);
        }
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
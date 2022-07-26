class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> st;
        char operation = '+';
        long long n = s.length(), curr_num = 0, ans = 0;
        
        // cout << operation << endl;
        
        for (int i = 0; i < n; i++) {
            // cout << operation << endl;
            if (s[i] >= 48 and s[i] <= 57) {
                curr_num = (curr_num*10)+(s[i] - '0');
                // cout << curr_num << endl;
            }         
            else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
                // cout << operation << endl;
                if (operation == '-') {
                    st.push(curr_num*(-1));
                }
                else if (operation == '+') {
                    st.push(curr_num);
                }
                else if (operation == '*') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp * curr_num);   
                }
                else if (operation == '/') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp / curr_num);
                }
                
                curr_num = 0;
                operation = s[i];
            }
        }
        
        // cout << st.size() << endl;
        
        while (!st.empty()) {
            // cout << st.top() << endl;
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
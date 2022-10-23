class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        long long n = tokens.size(), ans = 0;
        
        if (n == 1)
            return stoll(tokens[0]);
        
        for (auto s : tokens) {
            if (s == "+" or s == "-" or s == "/" or s == "*") {
                string temp1 = st.top();
                st.pop();
                string temp2 = st.top();
                st.pop();
                
                long long num1 = stoll(temp1), num2 = stoll(temp2);
                if (s == "+")
                    ans = num1 + num2;
                else if (s == "-")
                    ans = num2 - num1;
                else if (s == "/")
                    ans = num2 / num1;
                else 
                    ans = num2 * num1;
                
                st.push(to_string(ans));
            }
            else {
                st.push(s);
            }
        }
        
        return ans;
    }
};
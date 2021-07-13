class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.push(ch);
            }
            else {
                if (stack.empty() || (stack.top() == '(' && ch != ')') || (stack.top() == '[' && ch != ']') || (stack.top() == '{' && ch != '}')) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};
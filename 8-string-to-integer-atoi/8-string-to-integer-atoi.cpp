class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' and c <= '9';
    }
    
    int myAtoi(string s) {
        int n = s.length(), ans = 0;
        bool flag = false;
        
        if (n == 0)
            return 0;
        
        int i = 0;
        
        while (i < n and s[i] == ' ') {
            i++;
        }
        
        if (i < n) {
            if (s[i] == '-') {
                flag = true;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
        }
        
        while (i < n and isDigit(s[i])) {
            int digit = s[i] - '0';
            
            if (ans > (INT_MAX/10) or (ans == (INT_MAX/10)) and digit > 7) {
                if (flag)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            
            ans = (ans*10) + digit;
            i++;
        }
        
        if (flag)
            return -ans;
        else
            return ans;
    }
};
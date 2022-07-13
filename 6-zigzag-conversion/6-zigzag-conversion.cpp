class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int n = s.length(), curr_row = 0;
        bool down = false;
        
        if (numRows == 1)
            return s;
        
        vector<string> rows(min(numRows, n));
        
        for (int i = 0; i < n; i++) {
            rows[curr_row] += s[i];
            if (curr_row == 0 or curr_row == numRows-1)
                down = !down;
            if (down)
                curr_row += 1;
            else
                curr_row -= 1;
        }
        
        for (auto i : rows)
            ans += i;
        
        return ans;
    }
};
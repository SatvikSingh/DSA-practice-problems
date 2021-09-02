class Solution {
public:
    vector<string> ans;
    
    void chidori(int open, int close, int n, string curr) {
        if (curr.length() == 2*n) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            chidori(open+1, close, n, curr + '(');
        }
        if (close < open) {
            chidori(open, close+1, n, curr + ')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        chidori(0, 0, n, "");
        return ans;
    }
};
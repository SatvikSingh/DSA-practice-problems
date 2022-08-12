unordered_map<char, string> letters({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});

class Solution {
public:
    void helper(string& digits, string temp, vector<string>& ans, int i, int n) {
        if (i == n) {
            ans.push_back(temp);
        }
        else {
            string s = letters[digits[i]];
            
            for (int j = 0; j < s.length(); j++) {
                helper(digits, temp+s[j], ans, i+1, n);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        
        if (n == 0)
            return {};
        
        helper(digits, "", ans, 0, n);
        
        return ans;
    }
};
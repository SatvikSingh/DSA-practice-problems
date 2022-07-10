class Solution {
public:
    string helper(string s1, string s2) {
        int i = 0, j = 0, l1 = s1.length(), l2 = s2.length();
        
        while (i < l1 and j < l2) {
            if (s1[i] != s2[j]) {
                break;
            }
            i++; j++;
        }
        
        return s1.substr(0, i);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for (auto s : strs) {
            prefix = helper(prefix, s);
        }
        
        return prefix;
    }
};
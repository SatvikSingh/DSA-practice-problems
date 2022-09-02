class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length(), m = t.length();
        int i = n-1, j = m-1, count_s = 0, count_t = 0;
        
        while (i >= 0 or j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    count_s++;
                    i--;
                }
                else if (count_s > 0) {
                    count_s--;
                    i--;
                }
                else
                    break;
            }
            
            while (j >= 0) {
                if (t[j] == '#') {
                    count_t++;
                    j--;
                }
                else if (count_t > 0) {
                    count_t--;
                    j--;
                }
                else 
                    break;
            }
            
            if (i >= 0 and j >= 0 and s[i] != t[j])
                return false;
            
            if ((i >= 0) != (j >= 0))
                return false;
            
            i--;
            j--;
        }
        
        return true;
    }
};
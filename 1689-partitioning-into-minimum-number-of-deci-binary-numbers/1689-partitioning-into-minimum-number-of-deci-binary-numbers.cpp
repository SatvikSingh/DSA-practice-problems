class Solution {
public:
    int minPartitions(string n) {
        int len = n.length(), ans = 0;
        
        for (int i = 0; i < len; i++) {
            ans = max(ans, n[i] - '0');
        }
        
        return ans;
    }
};
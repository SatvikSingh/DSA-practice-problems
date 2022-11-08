class Solution {
public:
    bool dir = false;
    
    int helper(int n) {
        if (n == 1)
            return 1;
        
        if (dir) {
            dir = !dir;
            return 2 * helper(n/2);
        }
        else {
            dir = !dir;
            if (n%2 == 0)
                return 2 * helper(n/2) - 1;
            else
                return 2 * helper(n/2);
        }
    }
    
    int lastRemaining(int n) {
        if (n == 1)
            return 1;
        
        return 2 * helper(n/2);    
    }
};
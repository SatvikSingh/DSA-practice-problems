class Solution {
public:
    int helper(int n, int k) {
        if (n == 1) {
            return 0;
        }
        
        int ans = 0;
        ans = (helper(n-1, k)+k) % n;
        return ans;
    }
    
    int findTheWinner(int n, int k) {
        return helper(n, k) + 1;
    }
};
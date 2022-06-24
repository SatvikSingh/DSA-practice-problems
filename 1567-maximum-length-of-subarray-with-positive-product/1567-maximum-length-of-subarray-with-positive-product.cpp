class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int j, start = -1, end = -1, pos = 0, neg = 0;
            for (j = i; j < n; j++) {
                if (nums[j] > 0)
                    pos++;
                if (nums[j] < 0) {
                    neg++;
                    if (start == -1)
                        start = j;
                    end = j;
                }
                if (nums[j] == 0)
                    break;
            }
            
            if (neg % 2 == 0) {
                ans = max(ans, neg+pos);
            }
            
            if (neg % 2 == 1) {
                ans = max(j-start-1, ans);
                ans = max(end-i, ans);
            }
            
            i = j;
        }
        
        return ans;
    }
};
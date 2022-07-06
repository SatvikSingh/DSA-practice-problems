class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 2) {
            return n;
        }
        
        vector<int> dp_inc(n, 0);
        vector<int> dp_dec(n, 0);
        
        dp_inc[0] = 1; dp_dec[0] = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                dp_inc[i] = dp_dec[i-1] + 1;
                dp_dec[i] = dp_dec[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                dp_dec[i] = dp_inc[i-1] + 1;
                dp_inc[i] = dp_inc[i-1];
            }
            else {
                dp_dec[i] = dp_dec[i-1];
                dp_inc[i] = dp_inc[i-1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << dp_inc[i] << " ";
        }
        
        cout << endl;
        
        for (int i = 0; i < n; i++) {
            cout << dp_dec[i] << " ";
        }
        int ans = max(dp_inc[n-1], dp_dec[n-1]);
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n), suffix(n);
        int prod = 1;
        
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            prefix[i] = prod;
        }
        
        prod = 1;
        
        for (int i = n-1; i >= 0; i--) {
            prod *= nums[i];
            suffix[i] = prod;
        }
        
        // for (auto i : prefix)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : suffix)
        //     cout << i << " ";
        // cout << endl;
        
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = suffix[i+1];
            }
            else if (i == n-1) {
                ans[i] = prefix[i-1];
            }
            else {
                ans[i] = prefix[i-1]*suffix[i+1];
            }
        }
        
        return ans;
    }
};
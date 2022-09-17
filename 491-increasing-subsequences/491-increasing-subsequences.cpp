class Solution {
public:
    set<vector<int>> set;
    void helper(vector<int>& nums, int idx, int n, vector<int>& temp) {
        if (temp.size() >= 2)
            set.insert(temp);
        
        if (idx >= n)
            return;
        
        for (int i = idx; i < n; i++) {
            if (temp.size() == 0 or nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                helper(nums, i+1, n, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        
        helper(nums, 0, n, temp);
        
        vector<vector<int>> ans(set.begin(), set.end());
        
        return ans;
    }
};
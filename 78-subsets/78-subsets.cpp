class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> temp, int idx) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        helper(ans, nums, temp, idx+1);
        temp.push_back(nums[idx]);
        helper(ans, nums, temp, idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(ans, nums, temp, 0);
        
        return ans;
    }
};
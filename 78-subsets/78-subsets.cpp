class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> temp, int idx) {
        ans.push_back(temp);
        
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(ans, nums, temp, i+1);
            temp.pop_back(); 
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(ans, nums, temp, 0);
        
        return ans;
    }
};
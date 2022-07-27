class Solution {
public:
    void helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target, int sum, int i) {  
        if (sum > target) {
            return;
        }
        
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        
        for (int j = i; j < candidates.size(); j++) {
            temp.push_back(candidates[j]);
            sum += candidates[j];
            helper(candidates, ans, temp, target, sum, j);
            temp.pop_back();
            sum -= candidates[j];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(candidates, ans, temp, target, 0, 0);
        
        return ans;
    }
};
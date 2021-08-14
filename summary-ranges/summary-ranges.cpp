class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size(), start = 0, end = 0;
        
        for (int i = 0; i < n; i++) {
            start = nums[i];
            
            while (i+1 < n and nums[i+1] == nums[i]+1) {
                i++;
            }
            
            if (start != nums[i]) {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else {
                ans.push_back(to_string(start));
            }
        }
        return ans;
    }
};
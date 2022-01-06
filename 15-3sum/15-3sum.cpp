class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        if (n == 0) {
            return {};
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 and nums[i] == nums[i-1]) {
                continue;
            }
            
            int left = i+1, right = n-1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    int last_left_occ = nums[left], last_right_occ = nums[right];
                    while (left < right and last_left_occ == nums[left]) {
                        left++;
                    }
                    while (left < right and last_right_occ == nums[right]) {
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};
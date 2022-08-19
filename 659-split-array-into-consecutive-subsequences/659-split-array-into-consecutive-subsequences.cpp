class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map, last_ocurr;
        
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (map[nums[i]] == 0)
                continue;
            
            if (last_ocurr[nums[i]-1] > 0) {
                map[nums[i]]--;
                last_ocurr[nums[i]]++;
                last_ocurr[nums[i]-1]--;
            }
            else {
                if (map[nums[i]+1] == 0 or map[nums[i]+2] == 0)
                    return false;
                
                map[nums[i]]--;
                map[nums[i]+1]--;
                map[nums[i]+2]--;
                last_ocurr[nums[i]+2]++;
            }
        }
        
        return true;
    }
};
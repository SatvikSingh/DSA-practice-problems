class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> map;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        
        for (auto i : map) {
            if (i.second == 1)
                return i.first;
        }
        
        return 0;
    }
};
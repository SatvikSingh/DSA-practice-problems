class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int temp1 = INT_MAX, temp2 = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= temp1) {
                temp1 = nums[i];
                // cout << "temp1: " << temp1 << endl;
            }
            else if (nums[i] <= temp2) {
                temp2 = nums[i];
                // cout << "temp2: " << temp2 << endl;
            }
            else {
                // cout << temp1 << " " << temp2 << endl;
                return true;
            }
        }
        
        return false;
    }
};
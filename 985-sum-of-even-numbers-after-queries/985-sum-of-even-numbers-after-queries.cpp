class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }
        
        for (auto i : queries) {
            int temp = nums[i[1]];
            nums[i[1]] += i[0];
            if (nums[i[1]] % 2 == 0) {
                if (temp % 2 == 0) {
                    sum -= temp;
                    sum += nums[i[1]];
                }
                else 
                    sum += nums[i[1]];
            }
            else {
                if (temp % 2 == 0) {
                    sum -= temp;
                }
                // else {
                //     continue; 
                // }
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};

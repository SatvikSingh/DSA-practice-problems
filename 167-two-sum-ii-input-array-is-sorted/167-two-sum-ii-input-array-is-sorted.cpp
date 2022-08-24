class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int i = 0, j = n-1;
        
        while (i < j) {
            int second = target - numbers[i];
            
            if (numbers[j] == second) {
                ans = {i+1, j+1};
                break;
            }
            else if (numbers[j] < second) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return ans;
    }
};
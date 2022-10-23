class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while (j < n) {
            while (!q.empty() and nums[q.back()] < nums[j]) {
                q.pop_back();
            }
            
            q.push_back(j);
            
            if (i > q.front()) {
                q.pop_front();
            }
            
            if (j+1 >= k) {
                ans.push_back(nums[q.front()]);
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};
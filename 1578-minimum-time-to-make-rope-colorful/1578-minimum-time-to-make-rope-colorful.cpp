class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0, i = 0, j = 0;
        
        while (i < n and j < n) {
            int curr = 0, curr_max = INT_MIN;
            
            while (j < n and colors[i] == colors[j]) {
                curr += neededTime[j];
                curr_max = max(curr_max, neededTime[j]);
                j++;
            }
            
            ans += (curr - curr_max);
            i = j;
        }
        
        return ans;
    }
};
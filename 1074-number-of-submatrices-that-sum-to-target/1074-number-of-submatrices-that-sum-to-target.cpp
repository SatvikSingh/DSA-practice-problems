class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        map<int, int> map;
        vector<int> cols;
        
        for (int i = 0; i < n; i++) {
            cols = matrix[i];
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += cols[k];
                    if (sum == target)
                        ans++;
                    if (map.count(sum-target))
                        ans += map[sum-target];
                    map[sum]++;
                    if (j < n-1)
                        cols[k] += matrix[j+1][k];
                }
                map.clear();
            }
        }
        
        return ans;
    }
};
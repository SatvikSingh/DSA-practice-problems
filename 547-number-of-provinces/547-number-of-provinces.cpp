class Solution {
public:
    void helper(vector<vector<int>>& isConnected, vector<int>& visited, int i, int n) {
        visited[i] = 1;
        
        for (int x = 0; x < n; x++) {
            if (isConnected[i][x] == 1 and visited[x] == 0) {
                helper(isConnected, visited, x, n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<int> visited(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                helper(isConnected, visited, i, n);
            }
        }
        
        return ans;
    }
};
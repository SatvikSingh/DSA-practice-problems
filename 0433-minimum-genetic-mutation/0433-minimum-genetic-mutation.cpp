class Solution {
public:
    int helper(string start, string end, vector<string>& bank, vector<bool>& visited, int idx) {
        // cout << start << endl;
        if (start == end)
            return 0;
        
        
        visited[idx] = true;
        int ans = 100;
        
        // cout << idx << endl;
        
        for (int i = 0; i < bank.size(); i++) {
            int count = 0;
            
            for (int j = 0; j < 8; j++) {
                if (bank[i][j] != start[j])
                    count++;
            }
            if (count <= 1 and visited[i] == false) {
                ans = min(helper(bank[i], end, bank, visited, i), ans);
            }
        }
        
        visited[idx] = false;
        
        ans++;
        return ans;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 100, n = bank.size();
        
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            for (int j = 0; j < 8; j++) {
                if (bank[i][j] != start[j])
                    count++;
            }
            
            if (count <= 1) {
                vector<bool> vis(n+1, false);
                ans = min(helper(start, end, bank, vis, n), ans);
            }
        }
        
        if (ans >= 100)
            return -1;
        else
            return ans;
    }
};
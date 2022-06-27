class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> map;
        vector<bool> dp(n+1, false);
        
        dp[0] = true;
        
        for (int i = 0; i < wordDict.size(); i++) {
            map[wordDict[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string substring = s.substr(j, i-j);
                if (dp[j] and map.count(substring)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
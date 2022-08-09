class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9+7;
        long long n = arr.size(), ans = 0;
        unordered_map<long long, long long> map;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++) {
            map[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0)
                    map[arr[i]] = (map[arr[i]] + map[arr[j]] * (map[arr[i] / arr[j]])) % mod;
            }
            ans = (ans + map[arr[i]]) % mod;
        }
        
        return ans;
    }
};
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        int count = 0, max_freq = s.size();
        
        for (auto i : s) {
            freq[i - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] > max_freq) {
                count += freq[i] - max_freq;
                freq[i] = max_freq;
            }
            max_freq = max(freq[i]-1, 0);
        }
        
        return count;
    }
};
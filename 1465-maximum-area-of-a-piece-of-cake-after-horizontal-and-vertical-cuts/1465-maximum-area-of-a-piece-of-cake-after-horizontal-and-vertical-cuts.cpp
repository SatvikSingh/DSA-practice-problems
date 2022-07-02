class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(h); horizontalCuts.push_back(0);
        verticalCuts.push_back(w); verticalCuts.push_back(0);
        
        long long n = horizontalCuts.size(), m = verticalCuts.size(), max_diff_h = 0, max_diff_v = 0;

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
//         for (auto i : horizontalCuts) {
//             cout << i << " ";
//         }
        
//         cout << endl;
        
//         for (auto i : verticalCuts) {
//             cout << i << " ";
//         }
        
        for (long long i = 0; i < n-1; i++) {
            long long diff = horizontalCuts[i+1] - horizontalCuts[i];
            if (diff > max_diff_h) {
                max_diff_h = diff;
                diff = 0;
            }
        }
        
        for (long long i = 0; i < m-1; i++) {
            long long diff = verticalCuts[i+1] - verticalCuts[i];
            if (diff > max_diff_v) {
                max_diff_v = diff;
                diff = 0;
            }
        }
    
        return (max_diff_h * max_diff_v) % 1000000007;
    }
};
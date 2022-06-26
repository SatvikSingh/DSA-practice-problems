class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, n = cardPoints.size();
        
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int max_sum = sum;
        int i = k-1, j = n-1;
        
        while (i >= 0) {
            sum += cardPoints[j] - cardPoints[i];
            max_sum = max(sum, max_sum);
            i--; j--;
        }
        
        return max_sum;
    }
};
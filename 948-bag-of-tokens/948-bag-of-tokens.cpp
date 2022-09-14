class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(), score = 0, ans = 0;
        
        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = n-1;
        
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                i++;
                score++;
                ans = max(score, ans);
            }
            else if (score > 0) {
                power += tokens[j];
                j--;
                score--;
            }
            else {
                break;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> helper = {a, b, c};
        
        sort(helper.begin(), helper.end());
        
        int diff1 = helper[1] - helper[0], diff2 = helper[2] - helper[1];
        
        if (diff1 == 1 and diff2 == 1)
            return {0, 0};
        else if (diff1 > 2 and diff2 > 2)
            return {2, diff1+diff2-2};
        else
            return {1, diff1+diff2-2};
    }
};
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size(), count = 0;
        set<int> set;
        
        
        for (int i = 0; i < n; i++) {
            set.insert(rolls[i]);
            if (set.size() == k) {
                count++;
                set.clear();
            }
        }
        
        return count+1;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0)
                s.push(asteroids[i]);
            else {
                while (!s.empty() and s.top() > 0 and abs(asteroids[i]) > s.top()) {
                    s.pop();
                }
                if (!s.empty() and s.top() == abs(asteroids[i])) {
                    s.pop();
                }
                else if (s.empty() or s.top() < 0) {
                    s.push(asteroids[i]);
                }
            }
        }
        
        if (s.empty())
            return {};
        
        while (!s.empty()) {
            int temp = s.top();
            s.pop();
            ans.push_back(temp);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
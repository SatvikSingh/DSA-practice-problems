class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        int n = position.size();
        stack<double> st;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({position[i], speed[i]});
        }
        
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        for (auto i : arr) {
            double pos = i.first;
            double speed = i.second;
            
            double time = (target - pos)/speed;
            
            // cout << time << endl;
            
            if (st.empty())
                st.push(time);
            
            if (st.top() < time)
                st.push(time);
        }
        
        return st.size();
    }
};
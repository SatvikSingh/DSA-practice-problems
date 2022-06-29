class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        int n = people.size();
        
        sort(people.begin(), people.end(), compare);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cout << people[i][j] << " ";
            }
            cout << endl;
        }
        
        for (auto i : people) {
            ans.insert(ans.begin() + i[1], i);
        }
        
        return ans;
    }
};
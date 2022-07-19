class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        map<int, vector<int>> stops;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                stops[routes[i][j]].push_back(i);
            }
        }
        
        // for (auto i : stops) {
        //     cout << i.first << " ";
        //     for (int j = 0; j < i.second.size(); j++) {
        //         cout << i.second[j] << " ";
        //     }
        //     cout << endl;
        // }
        
        map<int, bool> visited_stops;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                visited_stops[routes[i][j]] = false;
            }
        }
        
        // for (auto i : visited_stops) {
        //     cout << i.first << " " << i.second << endl;
        // }
        
        vector<int> visited_buses(n, 0);
        // int count = 0;
        queue<pair<int, int>> q;
        
        q.push({source, 0});
        visited_stops[source] = true;
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            int curr_pos = p.first, curr_count = p.second;
            
            if (curr_pos == target)
                return curr_count;
            
            vector<int> buses = stops[curr_pos];
            
            for (int i = 0; i < buses.size(); i++) {
                if (!visited_buses[buses[i]]) {
                    visited_buses[buses[i]] = 1;
                    vector<int> next_stops = routes[buses[i]];
                    for (int j = 0; j < next_stops.size(); j++) {
                        if (visited_stops[next_stops[j]])
                            continue;
                        else {
                            q.push({next_stops[j], curr_count+1});
                            visited_stops[next_stops[j]] = true;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};